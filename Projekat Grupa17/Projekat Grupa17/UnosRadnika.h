#pragma once
#include "Datum.h"
#include "Nasljedivanje.h"



class UnosRadnika : public Nasljedivanje
{
private:
	char imeR[20];
	char prezimeR[30];
	char gradR[20];
	char adresaR[20];
	Status statusR;
	Datum datumR;

public:
	UnosRadnika();
	void setIme();
	void setPrezime();
	void setGrad();
	void setAdresa();
	void setStatus();
	char* getIme();
	char* getPrezime();
	std::string getDatum();
	char* getGrad();
	char* getAdresa();
	int getStatus();
	void unesiRadnika();
	~UnosRadnika();
};
