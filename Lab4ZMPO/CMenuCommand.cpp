#include "pch.h"
#include "CMenuCommand.h"


CMenuCommand::CMenuCommand(string cMenuCommandComand, string cMenuCommandName, string cMenuCommandDescription)
{
	cCommandObject = NULL;
	sName = cMenuCommandName;
	sCommand = cMenuCommandComand;
}
CMenuCommand::CMenuCommand(string cMenuCommandComand, string cMenuCommandName, string cMenuCommandDescription,CCommand * newCCommandObject)
{
	sName = cMenuCommandName;
	sCommand = cMenuCommandComand;
	cCommandObject = newCCommandObject;
	this->cMenuCommandDescription = cMenuCommandDescription;
}
void CMenuCommand::setCCommandObject(CCommand * newCCommandObject)
{
	cCommandObject = newCCommandObject;
}
bool CMenuCommand::run()
{
	if (cCommandObject != NULL)
		return (cCommandObject)->runCommand();
	else
		cout << EMPTY_COMMAND << endl;
	return true;
}
string CMenuCommand::getCMenuCommandDescription()
{
	return string (cMenuCommandDescription);
}
CCommand * CMenuCommand::getCCommandObject()
{
	return cCommandObject;
}
CMenuCommand::~CMenuCommand()
{
	delete cCommandObject;
}
