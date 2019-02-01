#ifndef CMENUCOMMAND_H
#define CMENUCOMMAND_H
#include "CMenuItem.h"
#include "CCommand.h"

using namespace std;
const string EMPTY_COMMAND = "empty command";
class CMenuCommand: public CMenuItem
{
	CCommand * cCommandObject;
	string cMenuCommandDescription;
public:
	CMenuCommand(string cMenuCommandComand, string cMenuCommandName, string cMenuCommandDescription );
	CMenuCommand(string cMenuCommandComand, string cMenuCommandName, string cMenuCommandDescription, CCommand * newCCommandObject);
	//getters and setters
	CCommand * getCCommandObject();
	string getCMenuCommandDescription();
	void setCCommandObject(CCommand * newCCommandObject);

	bool run();
	~CMenuCommand();
};

#endif