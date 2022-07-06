#include "UnosFirme.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

UnosFirme::UnosFirme()
{
}

void UnosFirme::setImeFirme()
{
	cout << "Unesi ime firme: ";
	cin.getline(this->imeF, 20);
}

void UnosFirme::setGradFirme()
{
	cout << "Unesi grad firme: ";
	cin.getline(this->gradF, 20);
}

void UnosFirme::setAdresaFirme()
{
	cout << "Unesi adresu firme: ";
	cin.getline(this->adresaF, 40);
}

void UnosFirme::setMinPlate()
{
	for (int i = 0; i <= domar; i++) {
		cout << "Unesite min platu ("; ispisStatusa(i); cout << "): ";
		cin >> minPlataStat[i];
	}

}

void UnosFirme::setMaxPlate()
{
	float k;
	for (int i = 0; i <= domar; i++) {
		do
		{
			cout << "Unesite max platu ("; ispisStatusa(i); cout << "): \nNAPOMENA: Max plata mora biti veca od min\n";
			cin >> k;
		} while (k < minPlataStat[i]);
		maxPlataStat[i] = k;
	}
}

char* UnosFirme::getImeFirme()
{
	return imeF;
}

char* UnosFirme::getGradFirme()
{
	return gradF;
}

char* UnosFirme::getAdresaFirme()
{
	return adresaF;
}

float* UnosFirme::getMinPlate()
{
	return minPlataStat;
}

float* UnosFirme::getMaxPlate()
{
	return maxPlataStat;
}

void UnosFirme::unesiFirmu()
{
	this->setImeFirme();
	this->setGradFirme();
	this->setAdresaFirme();
	this->setMinPlate();
	this->setMaxPlate();
}

UnosFirme::~UnosFirme()
{
}