#include "UnosRadnika.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;

UnosRadnika::UnosRadnika()
{
}

void UnosRadnika::setIme()
{
	cout << "Unesi ime radnika: ";
	cin.getline(this->imeR, 20);
}

void UnosRadnika::setPrezime()
{
	cout << "Unesi prezime radnika: ";
	cin.getline(this->prezimeR, 30);
}

void UnosRadnika::setGrad()
{
	cout << "Unesi grad radnika: ";
	cin.getline(this->gradR, 20);
}

void UnosRadnika::setAdresa()
{
	cout << "Unesi adresu radnika: ";
	cin.getline(this->adresaR, 20);
}

void UnosRadnika::setStatus()
{
	int izbor;
	cout << "Koji je status radnika: ";
	cout << "\nSef = 0\nMenadzer = 1\nProgramer = 2\nDomar = 3\n";
	cin >> izbor;
	switch (izbor) {
	case 0:
		statusR = sef;
		break;
	case 1:
		statusR = menadzer;
		break;
	case 2:
		statusR = programer;
		break;
	case 3:
		statusR = domar;
		break;
	}
}

char* UnosRadnika::getIme()
{
	return this->imeR;
}

char* UnosRadnika::getPrezime()
{
	return this->prezimeR;
}

std::string UnosRadnika::getDatum()
{
	std::string datum;

	datum = datumR.getStringDatum();

	return datum;
}

char* UnosRadnika::getGrad()
{
	return this->gradR;
}

char* UnosRadnika::getAdresa()
{
	return this->adresaR;
}

int UnosRadnika::getStatus()
{
	return this->statusR;
}

void UnosRadnika::unesiRadnika()
{
	this->setIme();
	this->setPrezime();
	this->datumR.postaviDatum();
	cin.ignore();
	this->setGrad();
	this->setAdresa();
	this->setStatus();
}

UnosRadnika::~UnosRadnika()
{
}
