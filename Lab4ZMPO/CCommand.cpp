#include "pch.h"
#include "CCommand.h"
#include "ZmpoLab2Library.h"
CCommand::CCommand()
{
}
bool CCommand::runCommand() {
	std::cout << DEFAULT_COMMAND << std::endl;
	return true;
}

CCommand::~CCommand()
{
}


