#pragma once
#include "Nasljedivanje.h"
#include "CitajRadnika.h"
#include "CitajFirmu.h"

class Login : private Nasljedivanje
{
private:
	int kod;
	CitajFirmu citajF;
	CitajRadnika citajR;
public:
	Login();
	int provjeraSifre();
	void primanjaKorisnika();
	~Login();
};
