#include "Login.h"
#include <iostream>

using std::cin;
using std::cout;

const char* estetika3 = "*******************************************\n";

Login::Login()
{
}

int Login::provjeraSifre()
{
	for (int i = 3; i > 0; i--) {
		cout << estetika3;
		cout << "Unesite odgovarajucu lozinku za korisnika: \n\t(ostalo je " << i << " pokusaja)!\n";
		cout << estetika3;
		cin >> this->kod;
		try {
			if (this->kod <= 0) {
				throw	"Lozinka ne moze biti manja od nule!\n";
			}
			else if (this->kod == 0) {
				throw   "Lozinka ne moze biti nula!\n";
			}
			else {
				uzimanjeSifri();
				for (int i = 0; i < brojSifri; i++) {
					if (sifre[i] == this->kod)
					{
						cout << "\n\tUnesena je ispravna lozinka!\n\n";
						primanjaKorisnika();
						return 0;
					}
				}
			}
		}
		catch (const char* Greska) {
			std::cout << "[GRESKA] " << Greska;
		}
		catch (float n) {
			std::cout << "Lozinka ne moze biti " << n << "!\n";
		}
		catch (...) {
			std::cout << "Nepoznata greska!\n";
		}
	}
	cout << "Istekli su pokusaji!\n";
	system("Pause");
	system("cls");
	return 0;
}

void Login::primanjaKorisnika()
{
	int pozicijaOsobe;
	pozicijaOsobe = citajR.pretragaPoSifri(kod);
	citajR.ispisRadnika();
	int stat = citajR.getStatus(pozicijaOsobe);
	cout << "\tI platom izmedu " << citajF.getMinPlatu(stat) << " - " << citajF.getMaxPlatu(stat) << ".\n";
	system("pause");
	system("cls");
}

Login::~Login()
{
}
