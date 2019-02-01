#ifndef CGENETICALGORITHM_H
#define CGENETICALGORITHM_H
#include <time.h> 
#include <stdlib.h>

const int  POPULATION_SIZE = 200;
const double  CROSS_PROB = 0.70;
const double  MUT_PROB = 0.04;
const int I_ELITE_INDYVIDUALS = 2;
const int ITERATION_TIME = 500;
const int  NUMBER_OF_OPTIONS_IF_WE_TAKE_OBJECT_OR_NOT = 2;
const int  NUMBER_OF_OPTIONS_IN_BOOL = 2;
const int  NUMBER_OF_OPTIONS_IN_INT = RAND_MAX;

const int SIZE_OF_CHILDERN_TABLE = 2;

template < typename T >
class Problem 
{
public:
	  virtual double calculateValueofThisSolution(T * solutionTable) =0;
};
template < typename T >
class CIndividual
{
public:
	CIndividual(T * genotypeTable, int genotypeTableSize, double mutProb);
	double caltulateAdaptationOfTheIndividual(Problem<T> * cKnapsackProblem);
	void mutateIndividual();
	T getGenotypeTablePosition(int tablePosition);
	void mutateGen(int genotypeTablePosition);
	/**
	* returns table of pointers on two CIndividual class objects
	**/
	CIndividual ** crossIndividualWithOther(CIndividual * othercIndividual);
	CIndividual(CIndividual& otherCIndividual);
	~CIndividual();
	void operator++(int);
	CIndividual<T> operator*(CIndividual<T> * otherCIndividual);
	CIndividual operator+(CIndividual * otherCIndividual);
private:
	T * genotypeTable;
	double mutProb;
	int genotypeTableSize;
};
template < typename T >
class CGeneticAlgorithm
{
public:
	CGeneticAlgorithm(int genotypeLenght, Problem<T> * problem);
	T* runGeneticAlgorithm(int TimeOfRunningInSecundes);
	~CGeneticAlgorithm();
private:
	int genotypeLenght;
	int populationSize;
	int iEliteIndyviduals;
	double crossProb;
	double mutProb;
	Problem<T> * problem;
	CIndividual<T> ** population;
	void copyEliteIndyvidualsToNewPopulation(CIndividual<T> ** newPopulation,int newPopulationSize);
	T * takeGenotypeOfBestCIndividualFromPopulation();
	void makeCrosses();
	void makeMutations();
	void generateFullyRandomPopulation();
	CIndividual<T> ** MakeTwoChildren();
	int takeTwoRandomIndyvidualsAndChoseBetter();	
	double getAlgorytmStartingRandomNumber();
};
# endif
