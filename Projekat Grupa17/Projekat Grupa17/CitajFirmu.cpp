#include "CitajFirmu.h"
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

const char* estetika4 = "**********************************\n";

CitajFirmu::CitajFirmu()
{
}

void CitajFirmu::upisDatFirma()
{
	float* temp1;
	float* temp2;

	unosFirme.unesiFirmu();

	temp1 = unosFirme.getMinPlate();
	temp2 = unosFirme.getMaxPlate();

	std::ofstream datFirma("Firma.txt");

	datFirma << unosFirme.getImeFirme() << " " << unosFirme.getGradFirme() << " " << unosFirme.getAdresaFirme() << endl;



	for (int i = 0; i < 4; i++) {
		datFirma << *(temp1 + i) << " ";
	}
	datFirma << endl;

	for (int i = 0; i < 4; i++) {
		datFirma << *(temp2 + i) << " ";
	}
	datFirma << endl;

	datFirma.close();
	cin.ignore();

}

void CitajFirmu::citajDatFirma()
{

	std::ifstream datotekaFirma("firma.txt");

	if (datotekaFirma.is_open())
	{
		datotekaFirma >> this->imeFirme;
		datotekaFirma >> this->gradFirme;
		datotekaFirma >> this->adresaFirme;
		for (int i = 0; i < 4; i++) {
			datotekaFirma >> this->minPlataStatusa[i];
		}
		for (int i = 0; i < 4; i++) {
			datotekaFirma >> this->maxPlataStatusa[i];
		}
	}
	datotekaFirma.close();
}

void CitajFirmu::ispisFirme()
{
	citajDatFirma();
	cout << estetika4;
	cout << "\t\tFIRMA:\n";
	cout << "\tNaziv: " << this->imeFirme << endl;
	cout << "\tLokacija : " << this->gradFirme << ", " << this->adresaFirme << endl << endl;
	cout << "\tMin plate i max plate:\n";
	cout << "\tSef: " << this->minPlataStatusa[0] << " do " << this->maxPlataStatusa[0] << endl;
	cout << "\tMenader: " << this->minPlataStatusa[1] << " do " << this->maxPlataStatusa[1] << endl;
	cout << "\tRadnik: " << this->minPlataStatusa[2] << " do " << this->maxPlataStatusa[2] << endl;
	cout << "\tDomar: " << this->minPlataStatusa[3] << " do " << this->maxPlataStatusa[3] << endl;
}

int CitajFirmu::getMinPlatu(int n)
{
	citajDatFirma();
	return minPlataStatusa[n];
}

int CitajFirmu::getMaxPlatu(int n)
{
	citajDatFirma();
	return maxPlataStatusa[n];
}

CitajFirmu::~CitajFirmu()
{
}