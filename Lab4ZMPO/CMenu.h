#ifndef CMENU_H
#define CMENU_H
#include <vector>
#include <iostream>
#include "CMenuItem.h"
using namespace std;
class CMenu: public CMenuItem
{
	vector <CMenuItem *> * cMenuItemVector;
	CMenu * mainMenu;
	int cMenuItemsTablePositionByCommand(string cMenuItemCommand);
	int cMenuItemsTablePositionByName(string cMenuItemName);
	vector<string *> * SeachInMenu(string menuItemName);
	void DesplayMenuHelp(string menuItemName);
	string * getTreefromThisRoot(string * menuTree);
	string searchPathToCommandInTree(string menuItemName, int * whitchCommandWeSearchNow, string path);
public:
	CMenu( string menuCommand, string menuName, CMenu * mainMenu);
	///*constructor only for main menu*/
	CMenu(string menuCommand, string menuName);
	bool run();
	string * getAlltree();
	bool addNewCMenuItem(CMenuItem * cMenuItem);
	bool deleteCMenuItem(string cMenuItemCommand);
	~CMenu();
};

#endif