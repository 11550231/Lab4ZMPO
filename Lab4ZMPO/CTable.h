#ifndef CTABLE_H
#define CTABLE_H
#include <string>
using namespace std;
class CTable
{
private:
	const int MAIN_TABLE_DEFAULT_LENGTH = 10;
	int mainTableLength;
	int * mainTable;
	string sName;
public:
	CTable();
	CTable(string sName, int mainTableLength);
	CTable(const CTable &pcOther);
	bool changeTableSize(int newSize);
	bool writeValueInTableSpecifiedPosition(int newValue, int tablePosition);
	int readValueFromSpecifiedPosition(int tablePosition, bool * valueReturned);
	CTable * makeCloneOfThisObject();
	bool rewriteValuesFromTableToSpecifiedObject(CTable * tableDestinaion);
	string getInformationsAboutObject(bool * allInformationsReturned);
	void vSetName(string sName);
	~CTable();
};

#endif