#include "pch.h"
#include "CGeneticAlgorithm.h"
#include <ctime>
double randDouble()
{
	return (RAND_MAX) * ((double)rand() / (double)RAND_MAX);
}
int randPositiveInt()
{
	return rand();
}
template < class T >
CGeneticAlgorithm<T>::CGeneticAlgorithm(int genotypeLenght, Problem<T> * problem)
{
	srand(time(NULL));
	this->genotypeLenght = genotypeLenght;
	this->crossProb= CROSS_PROB;
	this->mutProb = MUT_PROB;
	this->problem = problem;
	this->populationSize = POPULATION_SIZE;
	population= new CIndividual<T>*[populationSize];
	this->iEliteIndyviduals = I_ELITE_INDYVIDUALS;
	generateFullyRandomPopulation();
}
template < class T >
int CGeneticAlgorithm<T>::takeTwoRandomIndyvidualsAndChoseBetter()
{
	int firstIndyvidualNumber = (rand() % populationSize);
	int secondIndyvidualNumber = (rand() % populationSize);
	if (population[firstIndyvidualNumber]->caltulateAdaptationOfTheIndividual(problem) > population[firstIndyvidualNumber]->caltulateAdaptationOfTheIndividual(problem))
		return firstIndyvidualNumber;
	return secondIndyvidualNumber;
}
template < class T >
CIndividual<T> ** CGeneticAlgorithm<T>::MakeTwoChildren()
{
	int firstParentNumber = takeTwoRandomIndyvidualsAndChoseBetter();
	int secondParentNumber = takeTwoRandomIndyvidualsAndChoseBetter();

	if (randDouble() <= crossProb)//we check if we are crossing indiwiduals
	{
		//returning crossed children
		return population[firstParentNumber]->crossIndividualWithOther(population[secondParentNumber]);
	}
	//returning copies of parents from previous generation
	return  (new CIndividual<T>*[SIZE_OF_CHILDERN_TABLE]{ new CIndividual<T>(*population[firstParentNumber]), new CIndividual<T>(*population[secondParentNumber]) });;
}
template < class T >
void CGeneticAlgorithm<T>::copyEliteIndyvidualsToNewPopulation(CIndividual<T> ** newPopulation,int newPopulationSize)
{
	for (int i = 0; i < iEliteIndyviduals; i++)
	{

		for (int j = i; j < populationSize; j++)
		{

				CIndividual<T> * bestIndyvidual = population[i];
				if (population[i]->caltulateAdaptationOfTheIndividual(problem) < population[j]->caltulateAdaptationOfTheIndividual(problem))
				{
					CIndividual<T> * currentIndyvidual = population[i];
					population[i] = population[j];
					population[j] = currentIndyvidual;
				}
		}
	}
	for (int i = 0; i < iEliteIndyviduals; i++)
	{
		newPopulation[i] = population[i];
	}
}
template < class T >
void CGeneticAlgorithm<T>::makeCrosses()
{
	int newPopulationSize= populationSize;
	CIndividual<T> ** newPopulation= new CIndividual<T>*[newPopulationSize];
	int i = 0;
	copyEliteIndyvidualsToNewPopulation(newPopulation,newPopulationSize);
	for (int i = iEliteIndyviduals; i < newPopulationSize; i++)
	{
		CIndividual<T> ** newChildren = MakeTwoChildren();
		CIndividual<T> * secondChild = newChildren[1];
			newPopulation[i++] = newChildren[0];
		if (i < (newPopulationSize))
			newPopulation[i] = secondChild;
		else
			delete secondChild;
		delete newChildren;
	}
	
	for (int i = iEliteIndyviduals; i < populationSize; i++)
		delete population[i];
	delete population;
	population = newPopulation;
	populationSize = newPopulationSize;
}
template < class T >
void CGeneticAlgorithm<T>::makeMutations()
{	
	for (int i = iEliteIndyviduals; i < populationSize; i++)
		(*(population[i]))++;
}
template < class T >
void CGeneticAlgorithm<T>::generateFullyRandomPopulation()
{
	for (int j = 0; j < populationSize; j++)
	{
		T * newGenotypeTable = new T[genotypeLenght];
		for (int k = 0; k < genotypeLenght; k++)
			newGenotypeTable[k] = getAlgorytmStartingRandomNumber();
		population[j] = new CIndividual<T>(newGenotypeTable, genotypeLenght, mutProb);
	}
}

double CGeneticAlgorithm<bool>::getAlgorytmStartingRandomNumber()
{
	return rand() % NUMBER_OF_OPTIONS_IN_BOOL;
}
double CGeneticAlgorithm<int>::getAlgorytmStartingRandomNumber()
{
	return rand();
}
double CGeneticAlgorithm<double>::getAlgorytmStartingRandomNumber()
{
	return randDouble();
}
template < class T >
T * CGeneticAlgorithm<T>::takeGenotypeOfBestCIndividualFromPopulation()
{
	double bestGenotypeValue = 0;
	int bestCIndividualTableNumber = 0;
	for (int i = 0; i < populationSize; i++)
	{
		if (bestGenotypeValue < population[i]->caltulateAdaptationOfTheIndividual(problem))
		{
			bestCIndividualTableNumber = i;
			bestGenotypeValue = population[i]->caltulateAdaptationOfTheIndividual(problem);
		}
	}
	T * bestGenotype = new T[genotypeLenght];
	for (int i = 0; i < genotypeLenght; i++)
		bestGenotype[i] = population[bestCIndividualTableNumber]->getGenotypeTablePosition(i);
	return bestGenotype;
}
template < class T >
T* CGeneticAlgorithm<T>::runGeneticAlgorithm(int timeOfRunningInSecundes)
{
	time_t timeWhenAlgorythmStarted = time(0);

	while((timeWhenAlgorythmStarted + timeOfRunningInSecundes)> time(0))
	{
		makeCrosses();
		makeMutations();
	}
	return  takeGenotypeOfBestCIndividualFromPopulation();
}
template < class T >
CGeneticAlgorithm<T>::~CGeneticAlgorithm()
{
	for (int i = 0; i < populationSize; i++)
		delete population[i];
	delete [] population;
}

template < class T >
CIndividual<T>::CIndividual(T * genotypeTable, int genotypeTableSize, double mutProb)
{
	this->genotypeTableSize = genotypeTableSize;
	this->genotypeTable = genotypeTable;
	this->mutProb = mutProb;
}
template < class T >
CIndividual<T>::CIndividual(CIndividual<T>& otherCIndividual)
{
	this->genotypeTableSize = otherCIndividual.genotypeTableSize;
	if (genotypeTable != nullptr)
		delete[] genotypeTable;
	this->genotypeTable = new T[genotypeTableSize];
	for (int i = 0; i < this->genotypeTableSize; i++)
		(this->genotypeTable)[i] = otherCIndividual.genotypeTable[i];
}
template < class T >
T CIndividual<T>::getGenotypeTablePosition(int tablePosition)
{
	return genotypeTable[tablePosition];
}

template < class T >
double CIndividual<T>::caltulateAdaptationOfTheIndividual(Problem<T> * problem)
{
	return problem->calculateValueofThisSolution(this->genotypeTable);
}
template < class T >
void CIndividual<T>::operator++(int)
{
	mutateIndividual();
}

template < class T >
CIndividual<T> CIndividual<T>:: operator*(CIndividual<T> * otherCIndividual)
{
	T * childGenotype = new T[genotypeTableSize];
	for (int i = 0; i < genotypeTableSize; i++)
	{
		T firstParentGen = this->getGenotypeTablePosition(i);
		T secondParentGen = otherCIndividual->getGenotypeTablePosition(i);
		if(firstParentGen == secondParentGen)
			childGenotype[i] = firstParentGen;
		else
			mutateGen(childGenotype[i]);
	}
		return new CIndividual<T>(childGenotype, genotypeTableSize, mutProb);
}
template < class T >
CIndividual<T> ** CIndividual<T>::crossIndividualWithOther(CIndividual * othercIndividual)
{


	T * firstChildGenotype = new T[genotypeTableSize];
	T * secondChildGenotype = new T[genotypeTableSize];

	for (int i = 0; i < SIZE_OF_CHILDERN_TABLE; i++)
	{
		int positionBeforeWeCut = (rand() % (genotypeTableSize - 1)) + 1;
		for (int i = 0; i < positionBeforeWeCut; i++)
		{
			firstChildGenotype[i] = this->getGenotypeTablePosition(i);
			secondChildGenotype[i] = othercIndividual->getGenotypeTablePosition(i);
		}
		for (int i = positionBeforeWeCut; i < genotypeTableSize; i++)
		{
			firstChildGenotype[i] = othercIndividual->getGenotypeTablePosition(i);
			secondChildGenotype[i] = this->getGenotypeTablePosition(i);
		}
	}
	return (new CIndividual<T>*[SIZE_OF_CHILDERN_TABLE] {new CIndividual<T>(firstChildGenotype, genotypeTableSize, mutProb), new CIndividual<T>(secondChildGenotype, genotypeTableSize, mutProb)});
}
template < class T >
CIndividual<T> CIndividual<T>::operator+(CIndividual<T> * otherCIndividual)
{
	CIndividual<T> ** children=crossIndividualWithOther(otherCIndividual);
	CIndividual<T> * firstChild = children[0];
	delete children[1];
	delete children;
	return *firstChild;
}
template < class T >
void CIndividual<T>::mutateIndividual()
{
	for (int i = 0; i < this->genotypeTableSize; i++)
	{
		if (randDouble() <= mutProb)
		{
			this->mutateGen(i);
			
		}
	}
}
void CIndividual<bool>::mutateGen(int genotypeTablePosition)
{
	bool randBool = rand() % 2;
	this->genotypeTable[genotypeTablePosition] = randBool;
}
void CIndividual<int>::mutateGen(int genotypeTablePosition)
{
	int randInt2 = randPositiveInt();
	genotypeTable[genotypeTablePosition] = randInt2;
}
void CIndividual<double>::mutateGen(int genotypeTablePosition)
{
	genotypeTable[genotypeTablePosition] = randDouble();
}

template < class T >
CIndividual<T>::~CIndividual()
{
	if (genotypeTable != nullptr)
		delete[] genotypeTable;
}
template class Problem < int >;
template class Problem < bool >;
template class Problem < double >;
template class CGeneticAlgorithm < int >;
template class CGeneticAlgorithm < bool >;
template class CGeneticAlgorithm < double >;