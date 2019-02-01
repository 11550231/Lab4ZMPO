#ifndef CKNAPSACKPROBLEM_H
#define CKNAPSACKPROBLEM_H
#include "CGeneticAlgorithm.h"

const int TABLE_UNDEFINED = -1;
const int I_TAKE_THIS_OBJECT_TO_SOLUTION = 1;
const int I_DO_NOT_TAKE_THIS_OBJECT_TO_SOLUTION = 0;

template < typename T >
class Problem;
template < typename T >
class CKnapsackProblem: public Problem<T>
{

public:
	CKnapsackProblem();
	bool setInputData(int objectSizesAndValuesTableSize, double ** objectsValueAndSizesTable, int knapsackSize);
	bool checkIfInputDataAreSet();
	bool dataIsSet();
	int getSolutionSizesAndValuesTableSize();
	//dynamic table of bools
	T * calculateTheSolution(int timeOfCalculationInSecundes);
	~CKnapsackProblem();
	/**
	* solutionTable need to have the same size as objectSizesAndValuesTableSize
	**/
	double calculateValueofThisSolution(T * solutionTable);
private:
	// it's amount of objects
	int knapsackSize;
	int objectsSizesAndValuesTableSize;
	double ** objectsValueAndSizesTable;
};

#endif