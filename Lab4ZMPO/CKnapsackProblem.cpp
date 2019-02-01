#include "pch.h"
#include "CKnapsackProblem.h"

template < class T >
CKnapsackProblem<T>::CKnapsackProblem()
{
	objectsSizesAndValuesTableSize = TABLE_UNDEFINED;
	objectsValueAndSizesTable =nullptr;
}
template < class T >
int CKnapsackProblem<T>::getSolutionSizesAndValuesTableSize()
{
	return objectsSizesAndValuesTableSize;
}
template < class T >
bool CKnapsackProblem<T>::dataIsSet()
{
	if (objectsValueAndSizesTable == nullptr || objectsSizesAndValuesTableSize == TABLE_UNDEFINED)
		return false;
	return true;
}
template < class T >
bool CKnapsackProblem<T>::checkIfInputDataAreSet()
{
	if (objectsSizesAndValuesTableSize < 0 || objectsValueAndSizesTable == nullptr)
		return false;
	else
		return true;
}
template < class T >
T * CKnapsackProblem<T>::calculateTheSolution(int timeOfCalculationInSecundes)
{
	T * solution = CGeneticAlgorithm<T>(objectsSizesAndValuesTableSize, this).runGeneticAlgorithm(timeOfCalculationInSecundes);
	return solution;
}
template < class T >
bool CKnapsackProblem<T>::setInputData(int objectSizesAndValuesTableSize, double ** objectSizesAndValuesTable, int knapsackSize)
{
	if (objectSizesAndValuesTableSize < 0 || objectSizesAndValuesTable == nullptr || knapsackSize<0)
		return false;
	this->objectsSizesAndValuesTableSize = objectSizesAndValuesTableSize;
	this->knapsackSize = knapsackSize;
	this->objectsValueAndSizesTable = objectSizesAndValuesTable;
	return true;

}

template < class T >
double CKnapsackProblem<T>::calculateValueofThisSolution(T * solutionTable)
{
	double valueofThisSolution = 0;
	double sizeofThisSolution = 0;
	
		for (int i = 0; i < objectsSizesAndValuesTableSize; i++)
		{
				valueofThisSolution += (objectsValueAndSizesTable[i][0])*(solutionTable[i]);
				sizeofThisSolution += (objectsValueAndSizesTable[i][1])*(solutionTable[i]);
		}
		if (sizeofThisSolution > knapsackSize)
			return -1;
		else
			return valueofThisSolution;
}
template < class T >
CKnapsackProblem<T>::~CKnapsackProblem()
{
	for(int i=0; i< objectsSizesAndValuesTableSize; i++)
		delete [](objectsValueAndSizesTable[i]);
	delete[] objectsValueAndSizesTable;
}
template class CKnapsackProblem < int >;
template class CKnapsackProblem < bool >;
template class CKnapsackProblem < double >;
