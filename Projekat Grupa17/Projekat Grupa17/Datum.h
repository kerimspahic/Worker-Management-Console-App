#pragma once
#include <iostream>

using std::cout;
using std::cin;

class Datum
{

private:
	int dan, mjesec, godina;
	std::string dat = "";
public:
	Datum();
	void setGodinu();
	void setMjesec();
	void setDan();
	int getGodina();
	int getMjesec();
	int getDan();
	void postaviDatum();
	void ispisDatum();
	void stringDatum();
	std::string getStringDatum();
	~Datum() {
	};
};
