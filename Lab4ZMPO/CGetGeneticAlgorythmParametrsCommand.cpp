#include "pch.h"
#include "CGetGeneticAlgorythmParametrsCommand.h"
#include "ZmpoLab2Library.h"
#include "LAB4zmpo.h"
template <class T>
CGetGeneticAlgorythmParametrsCommand<T>::CGetGeneticAlgorythmParametrsCommand(CKnapsackProblem<T> * cKnapsackProblem):CKnoapsackProblemCommand<T>(cKnapsackProblem)
{
}
template <class T>
bool CGetGeneticAlgorythmParametrsCommand<T>::runCommand()
{
	
	
	int amountOfProductYouCanStickIntoKnapsack;
	cout << GIVE_AMOUNT_OF_OBJECTS_YOU_CAN_STICK_INTO_KNOPSACK << endl;
	while ((!(cin >> amountOfProductYouCanStickIntoKnapsack)) || (amountOfProductYouCanStickIntoKnapsack < 0)|| (amountOfProductYouCanStickIntoKnapsack > MAXIMUM_AMOUNT_OF_OBJECTS_YOU_CAN_STICK_INTO_KNOPSACK))
	{
		cout << INCORECT_AMOUNT_OF_OBJECTS_YOU_CAN_STICK_INTO_KNOPSACK_WRITE_IT_AGAIN << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), NEW_LINE);
	}

	int knapsackSize;
	cout << GIVE_KANPSACK_SIZE << endl;
	while ((!(cin >> knapsackSize)) || (knapsackSize < 0))
	{
		cout << INCORECT_KANPSACK_SIZE_WRITE_IT_AGAIN << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), NEW_LINE);
	}
	int knapsackProblemTableSize= amountOfProductYouCanStickIntoKnapsack;
	double ** knapsackProblemTable = new double*[knapsackProblemTableSize];
	for (int i = 0; i < knapsackProblemTableSize; i++)
	{

		knapsackProblemTable[i] = new double[2];

		cout << GIVE_PRODUCT_VALUE << i + 1 << endl;
		while ((!(cin >> knapsackProblemTable[i][0])) || (knapsackProblemTable[i][0] < 0))
		{
			cout << INCORECT_PRODUCT_ << i + 1 << WRITE_IT_AGAIN << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), NEW_LINE);
		}

		cout << GIVE_PRODUCT_SIZE << i + 1 << endl;
		while ((!(cin >> (knapsackProblemTable[i][1]))) || ((knapsackProblemTable[i][1]) < 0))
		{
			cout << INCORECT_PRODUCT << i + 1 << WRITE_IT_AGAIN << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), NEW_LINE);
		}

		
	}
	(this->cKnapsackProblem)->setInputData(amountOfProductYouCanStickIntoKnapsack, knapsackProblemTable, knapsackSize);
	return true;
}
template <class T>
CGetGeneticAlgorythmParametrsCommand<T>::~CGetGeneticAlgorythmParametrsCommand()
{
}
template class CGetGeneticAlgorythmParametrsCommand < int >;
template class CGetGeneticAlgorythmParametrsCommand < bool >;
template class CGetGeneticAlgorythmParametrsCommand < double >;