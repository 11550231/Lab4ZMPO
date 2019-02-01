#ifndef CRUNKNAPSACKPROBLEMCOMMAND_H
#define CRUNKNAPSACKPROBLEMCOMMAND_H
#include <string>
#include "CKnapsackProblem.h"
#include "CKnoapsackProblemCommand.h"
using namespace std;
const string GIVE_TIME_OF_CALCULATION_IN_SECUNDES = "Give time off calculation in secundes:";
const string INCORECT_TIME_WRITE_IT_AGAIN = "Incorect time, write it again";
const string SET_DATA_BEFORE = "Set data before";
const string VALUE_OF_SOLUTION = "Value of solution: ";
const string SOLUTION = "solution:";
const int ONE_HOUR_IN_SECUNDES = 60 * 60;

template < class T >
class CRunKnapsackProblemCommand :
	public CKnoapsackProblemCommand<T>
{
public:
	CRunKnapsackProblemCommand(CKnapsackProblem<T> * cKnapsackProblem);
	bool runCommand();
	
	 ~CRunKnapsackProblemCommand();
private:
	void writeSolution(T * solutionTable, int solutionTableLength);
};

#endif