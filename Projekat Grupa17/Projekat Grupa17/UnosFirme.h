#pragma once
#include "Nasljedivanje.h"

class UnosFirme : public Nasljedivanje
{
private:
	char imeF[20];
	char gradF[20];
	char adresaF[40];
	float minPlataStat[4];
	float maxPlataStat[4];
public:
	UnosFirme();
	void setImeFirme();
	void setGradFirme();
	void setAdresaFirme();
	void setMinPlate();
	void setMaxPlate();
	char* getImeFirme();
	char* getGradFirme();
	char* getAdresaFirme();
	float* getMinPlate();
	float* getMaxPlate();
	void unesiFirmu();
	~UnosFirme();
};
