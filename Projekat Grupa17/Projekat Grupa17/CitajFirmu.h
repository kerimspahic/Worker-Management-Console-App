#pragma once
#include "UnosFirme.h"
#include <string>

class CitajFirmu
{
private:
	std::string imeFirme;
	std::string gradFirme;
	std::string adresaFirme;
	float minPlataStatusa[4];
	float maxPlataStatusa[4];
	UnosFirme unosFirme;

public:
	CitajFirmu();
	void upisDatFirma();
	void citajDatFirma();
	void ispisFirme();
	int getMinPlatu(int n);
	int getMaxPlatu(int n);
	~CitajFirmu();
};
