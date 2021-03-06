// Lab4ZMPO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdlib.h>
#include "pch.h"
#include <string>
#include "LAB4zmpo.h"
#include "CMenu.h"
#include "CMenuCommand.h"
#include "ZmpoLab2Library.h"
#include "CGetGeneticAlgorythmParametrsCommand.h"
#include "CRunKnapsackProblemCommand.h"
#include "CKnapsackProblem.h"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>

using namespace std;

void waitForKey()
{
	cout << endl << TAB_KEY_TO_CONTINUE << endl << endl;
	_getch();
}


CMenu *  initializeCKnapsackProblemMainMenu()
{


	CMenu * mainMenu=new CMenu(MAIN, MAIN_MENU);

	CKnapsackProblem<bool> * cKnapsackProblemBool = new CKnapsackProblem<bool>();
	CMenu * menuBool = new CMenu(MENUB, MENU_BOOL);
	menuBool->addNewCMenuItem(new CMenuCommand(PARAMS, SET_KNAPSACK_PROBLEM_PARAMETRS, SETTING_KNAPSACK_PROBLEM_PARAMETRS, new CGetGeneticAlgorythmParametrsCommand<bool>(cKnapsackProblemBool)));
	menuBool->addNewCMenuItem(new CMenuCommand(RUN_TIME, RUN_ITERATION, ENDS_THE_PROGRAM, new CRunKnapsackProblemCommand<bool>(cKnapsackProblemBool)));
	mainMenu->addNewCMenuItem(menuBool);

	CKnapsackProblem<int> * cKnapsackProblemInt = new CKnapsackProblem<int>();
	CMenu * menuInt = new CMenu(MENUI, MENU_INT);
	menuInt->addNewCMenuItem(new CMenuCommand(PARAMS, SET_KNAPSACK_PROBLEM_PARAMETRS, SETTING_KNAPSACK_PROBLEM_PARAMETRS, new CGetGeneticAlgorythmParametrsCommand<int>(cKnapsackProblemInt)));
	menuInt->addNewCMenuItem(new CMenuCommand(RUN_TIME, RUN_ITERATION, ENDS_THE_PROGRAM, new CRunKnapsackProblemCommand<int>(cKnapsackProblemInt)));
	mainMenu->addNewCMenuItem(menuInt);

	CKnapsackProblem<double> * cKnapsackProblemDouble = new CKnapsackProblem<double>();
	CMenu * menuDouble = new CMenu(MENUD, MENU_DOUBLE);
	menuDouble->addNewCMenuItem(new CMenuCommand(PARAMS, SET_KNAPSACK_PROBLEM_PARAMETRS, SETTING_KNAPSACK_PROBLEM_PARAMETRS, new CGetGeneticAlgorythmParametrsCommand<double>(cKnapsackProblemDouble)));
	menuDouble->addNewCMenuItem(new CMenuCommand(RUN_TIME, RUN_ITERATION, ENDS_THE_PROGRAM, new CRunKnapsackProblemCommand<double>(cKnapsackProblemDouble)));
	mainMenu->addNewCMenuItem(menuDouble);
	return mainMenu;
}

int runMenu()
{
	CMenu * mainMenu = initializeCKnapsackProblemMainMenu();
	mainMenu->run();
	delete mainMenu;
	return 0;
}

int main()
{
	runMenu();
	_CrtDumpMemoryLeaks();
	return 0;
}


//#define _CRTDBG_MAP_ALLOC  
//#include <stdlib.h>  
//#include <crtdbg.h>
//_CrtDumpMemoryLeaks();
/*
cKnapsackProblem->setInputData(CKNOCKSACK_TABLE_SIZE, initializeKnapsackProblemTable(), KANPSACK_SIZE);

T * cKnapsackProblemSolution = cKnapsackProblem->calculateTheSolution(POPULATION_SIZE, CROSS_PROB, MUT_PROB, I_ELITE_INDYVIDUALS, ITERATION_TIME);

for (int i = 0; i < CKNOCKSACK_TABLE_SIZE; i++)
	cout << (double)(cKnapsackProblemSolution[i]) << endl;

cout << endl << cKnapsackProblem->calculateValueofThisSolution(cKnapsackProblemSolution) << endl;
delete[] cKnapsackProblemSolution;*/



/*
srand(time(NULL));
main2();

*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
