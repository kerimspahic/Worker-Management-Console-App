#include "CitajRadnika.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using std::cout;
using std::endl;

const char* estetika5 = "*****************************************************************\n";

CitajRadnika::CitajRadnika()
{
}

void CitajRadnika::upisDatRad()
{
	this->unosRanika.unesiRadnika();
	this->createSifra();
	std::ofstream datRadnik("Radnici.txt", std::ios::app);
	datRadnik << this->unosRanika.getIme() << " " << this->unosRanika.getPrezime() << " " << this->unosRanika.getDatum() << " " << this->unosRanika.getGrad() << " " << this->unosRanika.getAdresa() << " " << this->unosRanika.getStatus() << " " << this->novaSifra << "\n";
	datRadnik.close();
	cin.ignore();
}

void CitajRadnika::pozivIzDat()
{
	this->imeRadnika.clear();
	this->prezimeRadnika.clear();
	this->datumRadnika.clear();
	this->gradRadnika.clear();
	this->adresaRadnika.clear();
	this->statusRadnika.clear();

	std::ifstream datRadnici("Radnici.txt");

	this->brojac = 0;
	string linija;

	while (std::getline(datRadnici, linija)) {
		brojac++;

		std::istringstream iss(linija);
		string rijec;

		if (linija.size() > 0) {
			while (iss >> rijec) {
				imeRadnika.push_back(rijec);
				break;
			}

			while (iss >> rijec) {
				prezimeRadnika.push_back(rijec);
				break;
			}

			while (iss >> rijec) {
				datumRadnika.push_back(rijec);
				break;
			}

			while (iss >> rijec) {
				gradRadnika.push_back(rijec);
				break;
			}

			while (iss >> rijec) {
				adresaRadnika.push_back(rijec);
				break;
			}

			while (iss >> rijec) {
				std::stringstream temp(rijec);
				int x1;
				temp >> x1;
				statusRadnika.push_back(x1);
				break;
			}

			while (iss >> rijec) {
				std::stringstream temp(rijec);
				int x2;
				temp >> x2;
				sifraRadnika.push_back(x2);
				break;
			}
		}
	}
}

void CitajRadnika::ispisDatotekeRadnici()
{
	pozivIzDat();
	cout << estetika5;
	cout.width(6); cout << "Ime: ";
	cout.width(12); cout << "Prezime: ";
	cout.width(21); cout << "Grad, adresa: ";
	cout.width(17); cout << "Status: \n";
	for (int i = 0; i < imeRadnika.size(); i++) {
		cout.width(6); cout << imeRadnika[i];
		cout.width(12); cout << prezimeRadnika[i];
		cout.width(11); cout << gradRadnika[i] << ", " << adresaRadnika[i];
		ispisStatusaZaFirm(statusRadnika[i]); cout << endl;
	}
}

void CitajRadnika::pretragaRad()
{
	this->pozivIzDat();
	string pojam = "";
	this->pozicija = -1;

	cout << "1. Ime,\n2. Prezime.\n";
	cout << "Izaberite na osnovu cega zelite pretrazivati: ";

	int unos;
	std::cin >> unos;
	do
	{
		switch (unos)
		{
		case 1:
			cout << "Unesite ime koje zelite pretraziti: ";
			std::cin >> pojam;
			for (int i = 0; i < imeRadnika.size(); i++) {
				if (this->imeRadnika[i].compare(pojam) == 0) {
					this->pozicija = i;
				}
			}
			break;
		case 2:
			cout << "Unesite prezime koje zelite pretraziti: ";
			std::cin >> pojam;
			for (int i = 0; i < prezimeRadnika.size(); i++) {
				if (this->prezimeRadnika[i].compare(pojam) == 0) {
					this->pozicija = i;
				}
			}
			break;
		}
	} while (unos < 1 || unos >4);

	if (this->pozicija != -1) {
		this->ispisRadnika();
	}
	else
	{
		cout << "Trazena osoba ne postoji!\n";
	}
}

int CitajRadnika::pretragaPoSifri(int n)
{
	pozivIzDat();
	for (int i = 0; i < sifraRadnika.size(); i++)
		if (sifraRadnika[i] == n) {
			pozicija = i;
			break;
		}
	return pozicija;
}

void CitajRadnika::ispisRadnika()
{
	cout << estetika5;
	cout << "\tIme: " << this->imeRadnika[pozicija] << endl;
	cout << "\tPrezime: " << this->prezimeRadnika[pozicija] << endl;
	cout << "\tDatum rodenja: " << this->datumRadnika[pozicija] << endl;
	cout << "\tLokacija: " << this->gradRadnika[pozicija] << ", " << this->adresaRadnika[pozicija] << endl;
	cout << "\tStatsa: "; this->ispisStatusa(this->statusRadnika[pozicija]); cout << ".\n";
}

void CitajRadnika::izmjenaRad()
{
	this->pretragaRad();

	cin.ignore();
	unosRanika.unesiRadnika();

	this->imeRadnika[pozicija] = this->unosRanika.getIme();
	this->prezimeRadnika[pozicija] = this->unosRanika.getPrezime();
	this->datumRadnika[pozicija] = this->unosRanika.getDatum();
	this->gradRadnika[pozicija] = this->unosRanika.getGrad();
	this->adresaRadnika[pozicija] = this->unosRanika.getAdresa();
	this->statusRadnika[pozicija] = this->unosRanika.getStatus();

	std::ofstream datoteka("Radnici.txt");
	if (datoteka.is_open()) {
		for (int i = 0; i < imeRadnika.size(); i++) {
			datoteka << this->imeRadnika[i] << " " << this->prezimeRadnika[i] << " " << this->datumRadnika[i] << " " << this->gradRadnika[i] << " " << this->adresaRadnika[i] << " " << this->statusRadnika[i] << " " << this->sifraRadnika[i] << endl;
		}
	}

	datoteka.close();
}

int CitajRadnika::getStatus(int n)
{
	return statusRadnika[n];
}

CitajRadnika::~CitajRadnika()
{
}
