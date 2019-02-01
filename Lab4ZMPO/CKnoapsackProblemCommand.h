#ifndef CKNOAPSACKPROBLEMCOMMAND_H
#define CKNOAPSACKPROBLEMCOMMAND_H
#include "CCommand.h"
#include "CKnapsackProblem.h"

template <class T>
class CKnoapsackProblemCommand: public CCommand
{
public:
	CKnoapsackProblemCommand(CKnapsackProblem<T>* cKnapsackProblem);
	virtual bool runCommand();
	virtual ~CKnoapsackProblemCommand();
protected:
	CKnapsackProblem<T> * cKnapsackProblem;
};

#endif