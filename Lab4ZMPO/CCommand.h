#ifndef CCOMMAND_H
#define CCOMMAND_H
#include<string>

#include<iostream>
class CCommand
{
public:
	CCommand();
	virtual bool runCommand();
	~CCommand();
};

#endif