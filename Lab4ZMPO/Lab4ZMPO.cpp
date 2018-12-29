// Lab4ZMPO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdlib.h>
#include "pch.h"
#include "LAB4zmpo.h"
#include <iostream>
#include "CKnapsackProblem.h"

using namespace std;

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

int main()
{
	CKnapsackProblem cKnapsackProblem;

	cKnapsackProblem.setInputData(CKNOCKSACK_TABLE_SIZE, initializeKnapsackProblemTable(), KANPSACK_SIZE);

	int * cKnapsackProblemSolution = cKnapsackProblem.calculateTheSolution(POPULATION_SIZE, CROSS_PROB, MUT_PROB, I_ELITE_INDYVIDUALS);

	for (int i = 0; i < CKNOCKSACK_TABLE_SIZE; i++)
		cout << cKnapsackProblemSolution[i] << endl;
	delete[] cKnapsackProblemSolution;

}


//#define _CRTDBG_MAP_ALLOC  
//#include <stdlib.h>  
//#include <crtdbg.h>

/*
srand(time(NULL));
main2();
_CrtDumpMemoryLeaks();
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
