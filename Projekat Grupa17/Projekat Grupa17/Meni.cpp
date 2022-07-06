#include "Meni.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using std::cout;
using std::cin;

const char* estetika = "************************************************************************\n";
const char* estetika2 = "**********************************\n";

Meni::Meni()
{
}

void Meni::provjeraDatoteki()
{
	std::ifstream datotekaRadnici("Radnici.txt");
	std::ifstream datotekaFirma("Firma.txt");

	if (datotekaRadnici.is_open() == false) {
		cout << estetika;
		cout << "Datoteka Radnici.txt ne postoji lil se nalazi pod drugim imenom!\n";
		cout << "Automatski je kreirana nova datoteka!\n";
		cout << "I biti ce pokrenuto prvo unosenje:\n";
		cout << estetika;
		system("pause");
		system("cls");
		citajR.upisDatRad();
	}
	if (datotekaFirma.is_open() == false) {
		cout << estetika;
		cout << "Datoteka Firma.txt ne postoji lil se nalazi pod drugim imenom!\n";
		cout << "Automatski je kreirana nova datoteka!\n";
		cout << "I biti ce biti pokrenuto prvo unosenje:\n";
		cout << estetika;
		system("pause");
		system("cls");
		citajF.upisDatFirma();
	}
}

void Meni::mainMeni()
{
	do
	{
		cout << estetika2;
		cout << "\t\tMENI\nIzaberi jednu od sljedecih opcija\n\n";
		cout << "\t1. Opcije radnika.\n";
		cout << "\t2. Opcije firme.\n";
		cout << "\t3. Login Radnika.\n";
		cout << "\t4. Izlaz.\n";
		cout << estetika2;
		cin >> this->izbor;
		switch (this->izbor) {
		case 1:
			system("cls");
			this->meniRadnici();
			break;
		case 2:
			system("cls");
			this->meniFirma();
			break;
		case 3:
			system("cls");
			this->meniLoginID();
			break;
		case 4:
			cout << "\n\tDovidenja!\n\n";
			break;
		default:
			system("cls");
			cout << "\n\tOpcija nije validna!\n\n";	break;
		}
	} while (this->izbor != 4);
}

void Meni::meniRadnici()
{
	do
	{
		cout << estetika2;
		cout << "\tMENI Zaposlenici\nIzaberi jednu od sljedecih opcija\n\n";
		cout << "\t1. Unos radnika.\n";
		cout << "\t2. Ispis radnika.\n";
		cout << "\t3. Pretraga radnika.\n";
		cout << "\t4. Izmjena radnika.\n";
		cout << "\t5. Nazad.\n";
		cout << estetika2;
		cin >> this->izbor;
		switch (this->izbor) {
		case 1:
			system("cls");
			cout << "Koliko radnika zelite unijeti: ";
			int x;
			cin >> x;
			cin.ignore();
			for (int i = 0; i < x; i++) {
				citajR.upisDatRad();
			}
			break;
		case 2:
			system("cls");
			citajR.ispisDatotekeRadnici();
			break;
		case 3:
			system("cls");
			citajR.pretragaRad();
			break;
		case 4:
			system("cls");
			citajR.izmjenaRad();
			break;
		case 5:
			system("cls");
			cout << "\n\tIzlaz!\n\n";
			break;
		default:
			system("cls");
			cout << "\n\tOpcija nije validna!\n\n";
			break;
		}
	} while (izbor != 5);
}

void Meni::meniFirma()
{
	do
	{
		cout << estetika2;
		cout << "\n\tMENI Firma\nIzaberi jednu od sljedecih opcija\n\n";
		cout << "\t1. Ispis firme.\n";
		cout << "\t2. Izmjena firme.\n";
		cout << "\t3. Nazad.\n";
		cout << estetika2;
		cin >> this->izbor;
		switch (this->izbor) {
		case 1:
			system("cls");
			citajF.ispisFirme();
			break;
		case 2:
			system("cls");
			cin.ignore();
			citajF.upisDatFirma();
			break;
		case 3:
			system("cls");
			cout << "\n\tIzlaz!\n\n";
			break;
		default:
			system("cls");
			cout << "\n\tOpcija nije validna!\n\n";
			break;
		}
	} while (izbor != 3);
}

void Meni::meniLoginID()
{
	login.provjeraSifre();
}