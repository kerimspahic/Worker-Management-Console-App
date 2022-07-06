#include "Datum.h"
#include <string>

Datum::Datum()
{
}

void Datum::setGodinu()
{
	do
	{
		cout << "Unesite godinu: ";
		cin >> this->godina;
		if (this->godina < 1900)
		{
			cout << "Datum ne moze biti manji od 1900!\n";
		}
	} while (this->godina < 1900);
}

void Datum::setMjesec()
{
	do
	{
		cout << "Unesite mjesec: ";
		cin >> this->mjesec;
		if (this->mjesec > 12 || this->mjesec < 1)
		{
			cout << "Unesen je pogresan mjesec!\n";
		}


	} while (this->mjesec < 1 || this->mjesec > 12);
}

void Datum::setDan()
{
	switch (this->mjesec) {
	case 1:case 3: case 5: case 7: case 8: case 10: case 12: {
		do
		{
			cout << "Unesite dan: ";
			cin >> this->dan;
			if (this->dan > 31)
			{
				cout << "Ovaj mjesec ima samo 31 dan!\n";
			}
			else if (this->dan < 1) {
				cout << "Dan u datumu ne moze biti manji od 1!";
			}

		} while (this->dan < 1 || this->dan > 31);
		break;
	}
	case 4:case 6: case 9: case 11: {
		do
		{
			cout << "Unesite dan: ";
			cin >> this->dan;
			if (this->dan > 30)
			{
				cout << "Ovaj mjesec ima samo 30 dana!\n";
			}
			else if (this->dan < 1) {
				cout << "Dan u datumu ne moze biti manji od 1!";
			}

		} while (this->dan < 1 || this->dan > 30);
		break;
	}
	case 2: {
		if (this->godina % 4 == 0) {
			cout << "Unesite dan: ";
			cin >> this->dan;
			if (this->dan > 29)
			{
				cout << "Ovaj mjesec ima samo 29 dana u prestupnoj godini!\n";
			}
			else if (this->dan < 1) {
				cout << "Dan u datumu ne moze biti manji od 1!";
			}
		}
		else {
			cout << "Unesite dan: ";
			cin >> this->dan;
			if (this->dan > 28)
			{
				cout << "Ovaj mjesec ima samo 28 dana!\n";
			}
			else if (this->dan < 1) {
				cout << "Dan u datumu ne moze biti manji od 1!";
			}
		}
		break;
	}
	default: {
		cout << "Mjesec ne postoji!";
	}
	}
}

int Datum::getGodina()
{
	return godina;
}

int Datum::getMjesec()
{
	return mjesec;
}

int Datum::getDan()
{
	return dan;
}

void Datum::postaviDatum()
{
	this->setGodinu();
	this->setMjesec();
	this->setDan();
	this->stringDatum();
}

void Datum::ispisDatum()
{
	cout << this->getDan() << "." << this->getMjesec() << "." << this->getGodina() << ".";

}

void Datum::stringDatum()
{

	dat += std::to_string(dan);
	dat += std::string(".");
	dat += std::to_string(mjesec);
	dat += std::string(".");
	dat += std::to_string(godina);
	dat += std::string(".");
}

std::string Datum::getStringDatum()
{
	return this->dat;
}