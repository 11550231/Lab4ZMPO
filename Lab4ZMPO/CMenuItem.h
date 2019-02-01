#ifndef CMENUITEM_H
#define CMENUITEM_H
#include <string>
#include <iostream>
class CMenuItem
{
protected:
	std::string sCommand;
	std::string sName;
public:
	//getters and setters
	std::string getSCommand();
	std::string getSName();

	bool virtual run() =0;

};

#endif