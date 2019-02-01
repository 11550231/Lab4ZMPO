#ifndef LAB4ZMPO_H
#define LAB4ZMPO_H
#include<string>
using namespace std;
//strings
const string MENUB = "menub";
const string MENU_BOOL = "Menu Binary knapsack problem";
const string PARAMS = "params";
const string SET_KNAPSACK_PROBLEM_PARAMETRS = "Set Knapsack Problem parametrs";
const string SETTING_KNAPSACK_PROBLEM_PARAMETRS ="Setting Knapsack Problem parametrs" ;
const string  RUN_TIME = "run time";
const string RUN_ITERATION ="Run iteration" ;
const string ENDS_THE_PROGRAM ="ends the program" ;
const string MENUI ="menui" ;
const string MENU_INT = "Menu Multi-choose single item knapsack problem";
const string MENUD = "menud";
const string  MENU_DOUBLE ="Menu Continuous knapsack problem" ;


const int CKNOCKSACK_TABLE_SIZE = 4;
const int KANPSACK_SIZE = 20;
static double **  initializeKnapsackProblemTable()
{

	double ** knapsackProblemTable = new double*[CKNOCKSACK_TABLE_SIZE];
	for (int i = 0; i < CKNOCKSACK_TABLE_SIZE; i++)
		knapsackProblemTable[i] = new double[2];
	knapsackProblemTable[0][0] = 5;
	knapsackProblemTable[0][1] = 4;

	knapsackProblemTable[1][0] = 1;
	knapsackProblemTable[1][1] = 1;

	knapsackProblemTable[2][0] = 4;
	knapsackProblemTable[2][1] = 3;

	knapsackProblemTable[3][0] = 3;
	knapsackProblemTable[3][1] = 2;
	return knapsackProblemTable;
}
#endif