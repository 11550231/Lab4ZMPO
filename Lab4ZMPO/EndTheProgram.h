#ifndef ENDTHEPROGRAM_H
#define ENDTHEPROGRAM_H


#include "CCommand.h"
class EndTheProgram :
	public CCommand
{
public:
	EndTheProgram();
	bool runCommand();
	~EndTheProgram();
};

#endif