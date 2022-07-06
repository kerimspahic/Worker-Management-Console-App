#pragma once
#include "UnosRadnika.h"
#include "UnosFirme.h"
#include "CitajFirmu.h"
#include "CitajRadnika.h"
#include "Login.h"



class Meni
{
private:
	int izbor = 0;
	UnosRadnika unosR;
	UnosFirme unosF;
	CitajRadnika citajR;
	CitajFirmu citajF;
	Login login;

public:
	Meni();
	void provjeraDatoteki();
	void mainMeni();
	void meniRadnici();
	void meniFirma();
	void meniLoginID();
	~Meni() {};

};
