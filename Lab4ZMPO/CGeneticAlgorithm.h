#ifndef CGENETICALGORITHM_H
#define CGENETICALGORITHM_H
#include <time.h> 
#include "Lab4zmpo.h"
#include <stdlib.h>
const int SIZE_OF_CHILDERN_TABLE = 2;

class Problem 
{
public:
	virtual double calculateValueofThisSolution(int * solutionTable)=0;
};

class CIndividual
{
public:
	CIndividual(int * genotypeTable, int genotypeTableSize, double mutProb);
	double caltulateAdaptationOfTheIndividual(Problem * cKnapsackProblem);
	void mutateIndividual();
	int getGenotypeTablePosition(int tablePosition);
	/**
	* returns table of pointers on two CIndividual class objects
	**/
	CIndividual ** crossIndividualWithOther(CIndividual * othercIndividual);
	CIndividual(CIndividual& otherCIndividual);
	~CIndividual();
	void operator++(int);
private:
	int * genotypeTable;
	double mutProb;
	int genotypeTableSize;
};

class CGeneticAlgorithm
{
public:
	CGeneticAlgorithm(int genotypeLenght, Problem * problem, int populationSize, double crossProb, double mutProb, int iEliteIndyviduals);
	int* runGeneticAlgorithm();
	~CGeneticAlgorithm();
private:
	int genotypeLenght;
	int populationSize;
	int iEliteIndyviduals;
	double crossProb;
	double mutProb;
	Problem * problem;
	CIndividual ** population;
	void copyEliteIndyvidualsToNewPopulation(CIndividual ** newPopulation,int newPopulationSize);
	int * takeGenotypeOfBestCIndividualFromPopulation();
	void makeCrosses();
	void makeMutations();
	void generateFullyRandomPopulation();
	CIndividual ** MakeTwoChildren();
	int takeTwoRandomIndyvidualsAndChoseBetter();	
};
# endif
