#ifndef CKNAPSACKPROBLEM_H
#define CKNAPSACKPROBLEM_H
#include "CGeneticAlgorithm.h"
#include "LAB4zmpo.h"
class Problem;

class CKnapsackProblem: public Problem
{

public:
	CKnapsackProblem();
	bool setInputData(int objectSizesAndValuesTableSize, double ** objectsValueAndSizesTable, int knapsackSize);
	bool checkIfInputDataAreSet();
	//dynamic table of bools
	int * calculateTheSolution(int populationSize, double crossProb, double mutProb,int iEliteIndyviduals);
	~CKnapsackProblem();
	/**
	* solutionTable need to have the same size as objectSizesAndValuesTableSize
	**/
	double calculateValueofThisSolution(int * solutionTable);
private:
	// it's amount of objects
	int knapsackSize;
	int objectsSizesAndValuesTableSize;
	double ** objectsValueAndSizesTable;
};

#endif