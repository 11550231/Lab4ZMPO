
#include "pch.h"
#include "CTable.h"
#include "iostream"
#include "stdio.h"
using namespace std;
const string LEN = " len: ";
const string VALUES = " values: ";
const char COMMA = ',';
const char SPACE = ' ';
const string SINGLE_QUOTATION_MARK = "'";
const string I_DELETE = "usuwam: '";
const string COPY = "_copy";
const string I_CREATE_NEW_OBJECT = "tworze nowy obiekt";
CTable::CTable()
{
	
	mainTable = new int[MAIN_TABLE_DEFAULT_LENGTH];
	mainTableLength = MAIN_TABLE_DEFAULT_LENGTH;
	for (int i = 0; i < mainTableLength; i++)
		mainTable[i] = 0;

	cout << I_CREATE_NEW_OBJECT << endl;
}

CTable::CTable(string sName, int mainTableLength)
{
	this->sName=sName;
	mainTable = new int[mainTableLength];
	this->mainTableLength = mainTableLength;
	for (int i = 0; i < mainTableLength; i++)
		mainTable[i] = 0;

	cout << I_CREATE_NEW_OBJECT << endl;
}

CTable::CTable(const CTable &pcOther)
{
	mainTable = new int[MAIN_TABLE_DEFAULT_LENGTH];
	mainTableLength = MAIN_TABLE_DEFAULT_LENGTH;
	string newObjectName= pcOther.sName + COPY;
	this->sName = newObjectName;
	for (int i = 0; i < mainTableLength; i++)
		mainTable[i] = 0;
	cout << I_CREATE_NEW_OBJECT << newObjectName << endl;
}

bool CTable::changeTableSize(int newSize)
{
	mainTableLength = newSize;
	mainTable = new int[newSize];
	for (int i = 0; i < newSize; i++)
		mainTable[i] = 0;
	return true;
}

bool CTable::writeValueInTableSpecifiedPosition(int newValue, int tablePosition)
{
	if (tablePosition >= mainTableLength)
		return false;
	else
		mainTable[tablePosition] = newValue;
	return true;
}

int CTable::readValueFromSpecifiedPosition(int tablePosition, bool * valueReturned)
{
	if (tablePosition >= mainTableLength)
	{
		*valueReturned = false;
		return 0;
	}
	else
	{
		*valueReturned = true;
		return mainTable[tablePosition];
	}
}

CTable * CTable::makeCloneOfThisObject()
{
	CTable * cTableClone = new CTable(this->sName, this->mainTableLength);
	rewriteValuesFromTableToSpecifiedObject(cTableClone);
	return cTableClone;
}

bool CTable::rewriteValuesFromTableToSpecifiedObject(CTable * tableDestinaion)
{
	if (tableDestinaion == NULL)
		return false;
	if (tableDestinaion->mainTableLength != mainTableLength)
		tableDestinaion->changeTableSize(mainTableLength);
	for (int i = 0; i < this->mainTableLength; i++)
	{
		bool readingValuesComplited = true;
		tableDestinaion->writeValueInTableSpecifiedPosition(readValueFromSpecifiedPosition(i, &readingValuesComplited), i);
		if (!readingValuesComplited)
			return false;
	}
	return true;
}

string CTable::getInformationsAboutObject(bool * allInformationsReturned)
{
	string infoAboutObject = sName + LEN + to_string(mainTableLength) + VALUES;
	for (int i = 0; i < mainTableLength-1 ; i++)
	{
		infoAboutObject += to_string(readValueFromSpecifiedPosition(i, allInformationsReturned)) + COMMA;
		if (!(*allInformationsReturned))
			return infoAboutObject;
	}
	infoAboutObject += (to_string(readValueFromSpecifiedPosition(mainTableLength - 1, allInformationsReturned))+ SPACE);//this line is to not have "," in end of text
	return infoAboutObject;
}

void CTable::vSetName(string sName)
{
	this->sName = sName;
}

CTable::~CTable()
{
	cout << I_DELETE << sName << SINGLE_QUOTATION_MARK << endl;
	if (mainTable != NULL)
		delete[] mainTable;

}
