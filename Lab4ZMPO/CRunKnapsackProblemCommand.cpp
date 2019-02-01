#include "pch.h"
#include "CRunKnapsackProblemCommand.h"
#include "ZmpoLab2Library.h"
#include <iostream>
using namespace std;
template<class T>
CRunKnapsackProblemCommand<T>::CRunKnapsackProblemCommand(CKnapsackProblem<T> * cKnapsackProblem):CKnoapsackProblemCommand<T>(cKnapsackProblem)
{
}
template<class T>
void CRunKnapsackProblemCommand<T>::writeSolution(T * solutionTable, int solutionTableLength)
{
	
	cout << SOLUTION;
	for (int i = 0; i < solutionTableLength; i++)
		cout << solutionTable[i] << " ";
	cout << endl;
	
	cout << VALUE_OF_SOLUTION << (this->cKnapsackProblem)->calculateValueofThisSolution(solutionTable) << endl;
}
template<class T>
bool CRunKnapsackProblemCommand<T>::runCommand() {
	if ((this->cKnapsackProblem) != nullptr)
	{
		if (((this->cKnapsackProblem)->dataIsSet()))
		{
			
			int timeInSecundes;
			cout << GIVE_TIME_OF_CALCULATION_IN_SECUNDES << endl;
			while ((!(cin >> timeInSecundes)) || timeInSecundes >= ONE_HOUR_IN_SECUNDES || (timeInSecundes < 0))
			{
				cout << INCORECT_TIME_WRITE_IT_AGAIN << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), NEW_LINE);
			}

			T * solutionTable=(this->cKnapsackProblem)->calculateTheSolution(timeInSecundes);
			int solutionTableLength = (this->cKnapsackProblem)->getSolutionSizesAndValuesTableSize();
			writeSolution(solutionTable, solutionTableLength);
			delete solutionTable;
			waitForKey();
			return true;
		}
		else
		{
			cout << SET_DATA_BEFORE << endl;
		}
	}
	return false;
}

template<class T>
CRunKnapsackProblemCommand<T>::~CRunKnapsackProblemCommand()
{
	delete this->cKnapsackProblem;
}
template class CRunKnapsackProblemCommand < int >;
template class CRunKnapsackProblemCommand < bool >;
template class CRunKnapsackProblemCommand < double >;