#include "pch.h"
#include "CMenu.h"
#include "CMenuCommand.h"
#include "ZmpoLab2Library.h"

CMenu::CMenu(string menuCommand , string menuName, CMenu * mainMenu)

{
	this->mainMenu = mainMenu;
	sName = menuName;
	sCommand = menuCommand;
	cMenuItemVector = new 	vector <CMenuItem *>;
}
CMenu::CMenu(string menuCommand, string menuName)
{
	mainMenu = this;
	sName = menuName;
	sCommand = menuCommand;
	cMenuItemVector = new 	vector <CMenuItem *>;
}
vector<string *> * CMenu::SeachInMenu(string menuItemName)
{
	vector<string *> * paths = new vector<string *>();
	int whitchCommandWeSearchNow = 0;
	string * path = new string();
	do
	{
		whitchCommandWeSearchNow = paths->size();
		path = new string(mainMenu->searchPathToCommandInTree(menuItemName, &whitchCommandWeSearchNow, EMPTY_STRING));
		if ((*path).compare(RIGHT_ARROW)!=0&&(*path).compare(RIGHT_ARROW)!=0)//path is not "->"
		{
			*path = mainMenu->sCommand +*path;
			paths->push_back(path);
		}
	} while ((*path).compare(RIGHT_ARROW) != 0 && (*path).compare(EMPTY_STRING) != 0);
	return paths;
}
string CMenu::searchPathToCommandInTree(string menuItemName, int * whitchCommandWeSearchNow , string path)
{

	for (int i= 0; i < this->cMenuItemVector->size(); i++)
	{
		if (!((*this->cMenuItemVector)[i])->getSCommand().compare(menuItemName))//if it is command, we search
		{
			if ((*whitchCommandWeSearchNow) > 0)
			{
				(*whitchCommandWeSearchNow)--;
			}
			else
				return (path + RIGHT_ARROW +((*this->cMenuItemVector)[i])->getSCommand());
			
		}
		const string EMPTY_STRING = "";
		const string RIGHT_ARROW = "->";
		const string SEMICOLON = ";";
		if (!(string(CLASS_CMENU).compare(typeid(*((*this->cMenuItemVector)[i])).name())))//if it is menu
		{
			string smallPath = ((CMenu *)(*this->cMenuItemVector)[i])->searchPathToCommandInTree(menuItemName, whitchCommandWeSearchNow, (path +RIGHT_ARROW + ((*this->cMenuItemVector)[i])->getSCommand()));
			if (((smallPath).compare(RIGHT_ARROW) != 0 && (smallPath).compare(EMPTY_STRING) != 0))
				return smallPath;
		}
	}
	return EMPTY_STRING;
}
string * CMenu::getAlltree()
{
	string * menuTree = new string(EMPTY_STRING);
	mainMenu->getTreefromThisRoot(menuTree);

	return menuTree;
}
string * CMenu::getTreefromThisRoot(string * menuTree)
{
	(*menuTree) += EMPTY_STRING+ LEFT_BRACKET+ QUATIATION_MARK + this->getSName() +QUATIATION_MARK + COMMA + QUATIATION_MARK + this->getSCommand() + QUATIATION_MARK +SEMICOLON;
	for (int i = 0; i < this->cMenuItemVector->size(); i++)
	{
		if (i > 0)
			(*menuTree) += COMMA;
		if (!(string(CLASS_CMENU).compare(typeid(*((*this->cMenuItemVector)[i])).name())))//if it is menu
		{
			((CMenu *)(*this->cMenuItemVector)[i])->getTreefromThisRoot(menuTree);
		}
		else  //it is menuCommand
		{
			(*menuTree) += EMPTY_STRING+ OPENING_CURLY_BRATCHED+ QUATIATION_MARK + ((*this->cMenuItemVector)[i])->getSName() + QUATIATION_MARK+ COMMA +QUATIATION_MARK + ((*this->cMenuItemVector)[i])->getSCommand()+ "','"+ ((CMenuCommand *)((*this->cMenuItemVector)[i]))->getCMenuCommandDescription() + "']";
		}
	}
	(*menuTree) += RIGHT_BRACKET;
	return menuTree;
}
void CMenu::DesplayMenuHelp(string menuItemName)
{

	int onWhitchPositionInCMenuItemVectorIsCommand = cMenuItemsTablePositionByCommand(menuItemName);
	if (onWhitchPositionInCMenuItemVectorIsCommand == -1)
		cout << LACK_OF_COMMAND << endl;
	else
		if (!(string(CLASS_CMENUCOMMAND).compare(typeid(*((*cMenuItemVector)[onWhitchPositionInCMenuItemVectorIsCommand])).name())))//if it is menu
		cout<< ((CMenuCommand *)(*cMenuItemVector)[onWhitchPositionInCMenuItemVectorIsCommand])->getCMenuCommandDescription() << endl;
		else
			cout << CMENU_OBJECTS_HAVENT_DESCRIPTION << endl;
}
bool CMenu::run()
{
	while(true)
	{
		string menuInputCommand;
		int cMenuItemNumber;
		cout << endl << PROGRAM_DISPLAYS << sName << endl;
		bool helpOrSearchUsed = false;
		for (int i = 0; i < cMenuItemVector->size(); i++)
			cout << i + 1 << DOT << (*cMenuItemVector)[i]->getSName() << LEFT_BRACKET << (*cMenuItemVector)[i]->getSCommand() << RIGHT_BRACKET << endl;
		bool canUseThisOptionNow=true;
		do
		{
			if (!canUseThisOptionNow)
				cout << YOU_CANT_USE_THIS_OPTION_NOW_CHOSE_ANOTHER_OPTION << endl;
			while ((!(getline(cin, menuInputCommand))) || ((cMenuItemNumber = cMenuItemsTablePositionByCommand(menuInputCommand)) == -1))
			{
				if (!menuInputCommand.compare(BACK))
				{
						return true;
				}
				else if ((menuInputCommand.rfind(HELP, 0) == 0))
				{
					DesplayMenuHelp(menuInputCommand.substr(5, menuInputCommand.length() - 1));
					helpOrSearchUsed = true;
				}
				else if ((menuInputCommand.rfind(SEARCH, 0) == 0))
				{
					vector<string *> * paths = SeachInMenu(menuInputCommand.substr(7, menuInputCommand.length()-1));
					for (int i = 0; i < paths->size(); i++)
						cout << *(*paths)[i] << endl;
					helpOrSearchUsed = true;
				}
				else
				{
					cout << THERE_IS_NOT_OPTION_LIKE_THIS << endl;
				}
				cin.clear();
			}
			if(!helpOrSearchUsed)
				canUseThisOptionNow = ((*cMenuItemVector)[cMenuItemNumber])->run();
		} while (!canUseThisOptionNow);
	}
	return true;
}

/**
	if isn't there returns -1
*/
int CMenu::cMenuItemsTablePositionByCommand(string cMenuItemCommand)
{

	for (int i = 0; i < cMenuItemVector->size(); i++)
		if (!((*cMenuItemVector)[i]->getSCommand()).compare(cMenuItemCommand))
			return i;

		return -1;
}
int CMenu::cMenuItemsTablePositionByName(string cMenuItemName)
{
	for (int i = 0; i < cMenuItemVector->size(); i++)
		if (!((*cMenuItemVector)[i])->getSName().compare(cMenuItemName))
			return i;

		return THERE_IS_NOT_SUCH_OBJECT;
}
bool CMenu::addNewCMenuItem(CMenuItem * cMenuItem)
{

 	if (cMenuItemsTablePositionByCommand(cMenuItem->getSCommand()) == -1&& cMenuItemsTablePositionByName(cMenuItem->getSName()) == -1)
	{
		(cMenuItemVector)->push_back(cMenuItem);
		return true;
	}
	else
		return false;
}
bool CMenu::deleteCMenuItem(string CMenuItemCommand)
{
	int cMenuItemsTablePosition;
	if ((cMenuItemsTablePosition = cMenuItemsTablePositionByCommand(CMenuItemCommand)) != -1)
	{
		delete (*cMenuItemVector)[cMenuItemsTablePosition];
	
		return true;
	}
	return false;
}
CMenu::~CMenu()
{
	for (int i = 0; i < (*cMenuItemVector).size(); i++)
		delete (*cMenuItemVector)[i];
	delete cMenuItemVector;
}
