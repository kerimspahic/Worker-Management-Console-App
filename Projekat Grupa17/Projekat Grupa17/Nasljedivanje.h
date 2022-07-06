#pragma once
#include <vector>

using std::vector;

class Nasljedivanje
{
protected:
	int novaSifra;
	vector <int> sifre;
	int brojSifri = 0;
public:
	Nasljedivanje();
	enum Status { sef = 0, menadzer, programer, domar };
	void uzimanjeSifri();
	void ispisStatusa(int n);
	void ispisStatusaZaFirm(int n);
	void createSifra();
	int getSifra();
	vector<int> getListuSifri();
	int getBrojSifri();
	~Nasljedivanje();
};
