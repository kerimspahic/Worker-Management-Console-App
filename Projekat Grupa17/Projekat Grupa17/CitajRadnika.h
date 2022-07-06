#pragma once
#include "Nasljedivanje.h"
#include "UnosRadnika.h"
#include "Datum.h"

using std::string;
using std::vector;

class CitajRadnika : public Nasljedivanje
{
private:
	vector <string> imeRadnika;
	vector <string> prezimeRadnika;
	vector <string> datumRadnika;
	vector <string> gradRadnika;
	vector <string> adresaRadnika;
	vector <int> statusRadnika;
	vector <int> sifraRadnika;

	UnosRadnika unosRanika;
	Datum datumR;
	int brojac;
	int pozicija = -1;
public:
	CitajRadnika();
	void upisDatRad();
	void pozivIzDat();
	void ispisDatotekeRadnici();
	void pretragaRad();
	int pretragaPoSifri(int n);
	void ispisRadnika();
	void izmjenaRad();
	int getStatus(int n);
	~CitajRadnika();
};
