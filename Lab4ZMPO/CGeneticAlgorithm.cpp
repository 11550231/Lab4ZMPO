#include "pch.h"
#include "CGeneticAlgorithm.h"

CGeneticAlgorithm::CGeneticAlgorithm(int genotypeLenght, Problem * problem, int populationSize, double crossProb, double mutProb, int iEliteIndyviduals)
{
	this->genotypeLenght = genotypeLenght;
	this->crossProb=crossProb;
	this->mutProb = mutProb;
	this->problem = problem;
	this->populationSize = populationSize;
	population= new CIndividual*[populationSize];
	this->iEliteIndyviduals = iEliteIndyviduals;
	generateFullyRandomPopulation();
}

int CGeneticAlgorithm::takeTwoRandomIndyvidualsAndChoseBetter()
{
	int firstIndyvidualNumber = (rand() % populationSize);
	int secondIndyvidualNumber = (rand() % populationSize);
	if (population[firstIndyvidualNumber]->caltulateAdaptationOfTheIndividual(problem) > population[firstIndyvidualNumber]->caltulateAdaptationOfTheIndividual(problem))
		return firstIndyvidualNumber;
	return secondIndyvidualNumber;
}
CIndividual ** CGeneticAlgorithm::MakeTwoChildren()
{
	int firstParentNumber = takeTwoRandomIndyvidualsAndChoseBetter();
	int secondParentNumber = takeTwoRandomIndyvidualsAndChoseBetter();

	if ((((double)(rand()) / (RAND_MAX))) <= crossProb)//we check if we are crossing indiwiduals
	{
		//returning crossed children
		return population[firstParentNumber]->crossIndividualWithOther(population[secondParentNumber]);
	}
	//returning copies of parents from previous generation
	return  (new CIndividual*[SIZE_OF_CHILDERN_TABLE]{ new CIndividual(*population[firstParentNumber]), new CIndividual(*population[secondParentNumber]) });;
}
void CGeneticAlgorithm::copyEliteIndyvidualsToNewPopulation(CIndividual ** newPopulation,int newPopulationSize)
{
	for (int i = 0; i < iEliteIndyviduals; i++)
	{

		for (int j = i; j < populationSize; j++)
		{

				CIndividual * bestIndyvidual = population[i];
				if (population[i]->caltulateAdaptationOfTheIndividual(problem) < population[j]->caltulateAdaptationOfTheIndividual(problem))
				{
					CIndividual * currentIndyvidual = population[i];
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
void CGeneticAlgorithm::makeCrosses()
{
	int newPopulationSize= populationSize;
	CIndividual ** newPopulation= new CIndividual*[newPopulationSize];
	int i = 0;
	copyEliteIndyvidualsToNewPopulation(newPopulation,newPopulationSize);
	for (int i = iEliteIndyviduals; i < newPopulationSize; i++)
	{
		CIndividual ** newChildren = MakeTwoChildren();
		CIndividual * secondChild = newChildren[1];
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

void CGeneticAlgorithm::makeMutations()
{	
	for (int i = iEliteIndyviduals; i < populationSize; i++)
		(*(population[i]))++;
}

void CGeneticAlgorithm::generateFullyRandomPopulation()
{
	for (int j = 0; j < populationSize; j++)
	{
		int * newGenotypeTable = new int[genotypeLenght];
		for (int k = 0; k < genotypeLenght; k++)
			newGenotypeTable[k] = (rand() % NUMBER_OF_OPTIONS_IF_WE_TAKE_OBJECT_OR_NOT);
		population[j] = new CIndividual(newGenotypeTable, genotypeLenght,mutProb);
	}
}
int * CGeneticAlgorithm::takeGenotypeOfBestCIndividualFromPopulation()
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
	int * bestGenotype = new int[genotypeLenght];
	for (int i = 0; i < genotypeLenght; i++)
		bestGenotype[i] = population[bestCIndividualTableNumber]->getGenotypeTablePosition(i);
	return bestGenotype;
}
int* CGeneticAlgorithm::runGeneticAlgorithm()
{

	for (int i = 0; i < AMOUNT_OF_ITERATIONS; i++)
	{
		makeCrosses();
		makeMutations();
	}
	return  takeGenotypeOfBestCIndividualFromPopulation();
}

CGeneticAlgorithm::~CGeneticAlgorithm()
{
	for (int i = 0; i < populationSize; i++)
		delete population[i];
	delete [] population;
}




CIndividual::CIndividual(int * genotypeTable, int genotypeTableSize, double mutProb)
{
	this->genotypeTableSize = genotypeTableSize;
	this->genotypeTable = genotypeTable;
	this->mutProb = mutProb;
}

CIndividual::CIndividual(CIndividual& otherCIndividual)
{
	this->genotypeTableSize = otherCIndividual.genotypeTableSize;
	if (genotypeTable != nullptr)
		delete[] genotypeTable;
	this->genotypeTable = new int[genotypeTableSize];
	for (int i = 0; i < this->genotypeTableSize; i++)
		(this->genotypeTable)[i] = otherCIndividual.genotypeTable[i];
}

int CIndividual::getGenotypeTablePosition(int tablePosition)
{
	return genotypeTable[tablePosition];
}


double CIndividual::caltulateAdaptationOfTheIndividual(Problem * problem)
{
	return problem->calculateValueofThisSolution(this->genotypeTable);
}
void CIndividual::operator++(int)
{
	mutateIndividual();
}
void CIndividual::mutateIndividual()
{
	for (int i = 0; i < this->genotypeTableSize; i++)
	{
		if ((((double)(rand()) / (RAND_MAX))) <= mutProb)
		{
			if (this->genotypeTable[i] == 0)
				this->genotypeTable[i] = 1;
			else
				this->genotypeTable[i] = 0;
		}
	}
}

CIndividual ** CIndividual::crossIndividualWithOther(CIndividual * othercIndividual)
{


	int * firstChildGenotype = new int[genotypeTableSize];
	int * secondChildGenotype = new int[genotypeTableSize];

	for (int i = 0; i < 2; i++)
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
	return (new CIndividual*[SIZE_OF_CHILDERN_TABLE] {new CIndividual(firstChildGenotype, genotypeTableSize, mutProb), new CIndividual(secondChildGenotype, genotypeTableSize, mutProb)});
}
CIndividual::~CIndividual()
{
	if (genotypeTable != nullptr)
		delete[] genotypeTable;
}
