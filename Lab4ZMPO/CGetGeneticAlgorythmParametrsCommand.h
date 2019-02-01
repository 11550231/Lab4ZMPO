#ifndef CGETGENETICALGORYTHMPARAMETRSCOMMAND_H
#define CGETGENETICALGORYTHMPARAMETRSCOMMAND_H
#include "CKnoapsackProblemCommand.h"
#include "CKnapsackProblem.h"
#include <string>
using namespace std;
const int MAXIMUM_AMOUNT_OF_OBJECTS_YOU_CAN_STICK_INTO_KNOPSACK = 100;
const string GIVE_AMOUNT_OF_OBJECTS_YOU_CAN_STICK_INTO_KNOPSACK = "Give amount of kinds of products, whitch you can strick into backpack";
const string INCORECT_AMOUNT_OF_OBJECTS_YOU_CAN_STICK_INTO_KNOPSACK_WRITE_IT_AGAIN = "Incorect amount of kinds of products";
const string GIVE_KANPSACK_SIZE = "Give size of knapsack";
const string WRITE_IT_AGAIN = " write it again";
const string INCORECT_KANPSACK_SIZE_WRITE_IT_AGAIN = "Incorect amount of kinds of products, "+ WRITE_IT_AGAIN;
const string INCORECT_PRODUCT = "incorect product number: ";
const string GIVE_PRODUCT_SIZE = "Give sie of product number ";
const string GIVE_PRODUCT_VALUE = "Give value of product number ";
const string INCORECT_PRODUCT_ = "Incorect product number";

template <class T>
class CGetGeneticAlgorythmParametrsCommand :
	public CKnoapsackProblemCommand<T>
{
public:
	CGetGeneticAlgorythmParametrsCommand(CKnapsackProblem<T> * cKnapsackProblem);
	bool runCommand();
	~CGetGeneticAlgorythmParametrsCommand();
};

#endif