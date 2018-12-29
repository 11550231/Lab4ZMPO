#include "pch.h"
#include "CKnapsackProblem.h"


CKnapsackProblem::CKnapsackProblem()
{
	objectsSizesAndValuesTableSize = TABLE_UNDEFINED;
	objectsValueAndSizesTable =nullptr;
}
bool CKnapsackProblem::checkIfInputDataAreSet()
{
	if (objectsSizesAndValuesTableSize < 0 || objectsValueAndSizesTable == nullptr)
		return false;
	else
		return true;
}
int * CKnapsackProblem::calculateTheSolution(int populationSize,double crossProb,double mutProb, int iEliteIndyviduals)
{

	int * solution = CGeneticAlgorithm(objectsSizesAndValuesTableSize, this, populationSize, crossProb, mutProb, iEliteIndyviduals).runGeneticAlgorithm();
	return solution;
}
bool CKnapsackProblem::setInputData(int objectSizesAndValuesTableSize, double ** objectSizesAndValuesTable, int knapsackSize)
{
	if (objectSizesAndValuesTableSize < 0 || objectSizesAndValuesTable == nullptr || knapsackSize<0)
		return false;
	this->objectsSizesAndValuesTableSize = objectSizesAndValuesTableSize;
	this->knapsackSize = knapsackSize;
	this->objectsValueAndSizesTable = objectSizesAndValuesTable;
	return true;

}
double CKnapsackProblem::calculateValueofThisSolution(int * solutionTable)
{
	double ValueofThisSolution = 0;
	double SizeofThisSolution = 0;
	for (int i = 0; i < objectsSizesAndValuesTableSize; i++)
	{
		if (solutionTable[i] == I_TAKE_THIS_OBJECT_TO_SOLUTION)
		{
			ValueofThisSolution += (objectsValueAndSizesTable[i][0]);
			SizeofThisSolution += (objectsValueAndSizesTable[i][1]);
		}
		else if (solutionTable[i] == I_DO_NOT_TAKE_THIS_OBJECT_TO_SOLUTION)
			;//do nothing
		else//wrong input data
			return 0;
	}
	if (SizeofThisSolution > knapsackSize)
		return 0;
	else
		return ValueofThisSolution;

}
CKnapsackProblem::~CKnapsackProblem()
{
	for(int i=0; i< objectsSizesAndValuesTableSize; i++)
		delete [](objectsValueAndSizesTable[i]);
	delete[] objectsValueAndSizesTable;
}
