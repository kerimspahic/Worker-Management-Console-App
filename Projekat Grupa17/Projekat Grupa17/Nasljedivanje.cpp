#include "Nasljedivanje.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>  
#include <time.h>

using std::cout;
using std::cin;

void Nasljedivanje::ispisStatusa(int n)
{
	switch (n) {
	case 0:
		cout << "sef";
		break;
	case 1:
		cout << "menadzer";
		break;
	case 2:
		cout << "programer";
		break;
	case 3:
		cout << "domar";
		break;
	}
}

void Nasljedivanje::ispisStatusaZaFirm(int n) {
	switch (n) {
	case 0:
		cout.width(15); cout << "sef";
		break;
	case 1:
		cout.width(15); cout << "menadzer";
		break;
	case 2:
		cout.width(15); cout << "programer";
		break;
	case 3:
		cout.width(15); cout << "domar";
		break;
	}
}


Nasljedivanje::Nasljedivanje()
{
}

void Nasljedivanje::uzimanjeSifri()
{
	std::ifstream datSifre("Sifre.txt");

	std::string line;
	int temp;

	if (datSifre.is_open())
		while (getline(datSifre, line)) {
			brojSifri++;
			datSifre >> temp;
			sifre.push_back(temp);
		}

	datSifre.close();
}

void Nasljedivanje::createSifra()
{
	this->uzimanjeSifri();
	bool provjera;
	do
	{
		provjera = true;
		srand(time(NULL));
		this->novaSifra = rand() % 10000000 + 1;
		for (int i = 0; i < this->sifre.size(); i++) {
			if (this->sifre[i] != this->novaSifra) {
				continue;
			}
			else {
				provjera = false;
			}
		}
	} while (provjera != true);

	cout << "Sifra radnika: " << this->novaSifra << "\n";

	std::ofstream newSifre("Sifre.txt", std::ios::app);
	newSifre << this->novaSifra << std::endl;
	newSifre.close();
}

int Nasljedivanje::getSifra()
{
	return this->novaSifra;
}

std::vector<int> Nasljedivanje::getListuSifri()
{
	return this->sifre;
}

int Nasljedivanje::getBrojSifri()
{
	return this->brojSifri;
}

Nasljedivanje::~Nasljedivanje()
{
}
