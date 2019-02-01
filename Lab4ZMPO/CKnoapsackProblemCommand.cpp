#include "pch.h"
#include "CKnoapsackProblemCommand.h"
#include "ZmpoLab2Library.h"
template < class T >
CKnoapsackProblemCommand<T>::CKnoapsackProblemCommand(CKnapsackProblem<T> * cKnapsackProblem)
{
	this->cKnapsackProblem = cKnapsackProblem;
}
template < class T >
bool CKnoapsackProblemCommand<T>::runCommand() {
	std::cout << DEFAULT_COMMAND << std::endl;
	return true;
}
template < class T >
CKnoapsackProblemCommand<T>::~CKnoapsackProblemCommand()
{

}
template class CKnoapsackProblemCommand < int >;
template class CKnoapsackProblemCommand < bool >;
template class CKnoapsackProblemCommand < double >;