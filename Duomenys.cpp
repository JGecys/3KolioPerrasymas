#include "Duomenys.h"



Duomenys::Duomenys() : Asmuo(""), Masina(""), Kiekis(0), Kilometrai(0), Tonos(0)
{}

Duomenys::Duomenys(string a, string m, int k, int km, int t) : Asmuo(a), Masina(m), Kiekis(k), Kilometrai(km), Tonos(t)
{}


Duomenys::~Duomenys()
{}

void Duomenys::Imti(string & asmuo, string & masina, int & kiekis, int & kilometrai, int & tonos)
{
	asmuo = Asmuo;
	masina = Masina;
	kiekis = Kiekis;
	kilometrai = Kilometrai;
	tonos = Tonos;
}

void Duomenys::Deti(string asmuo, string masina, int kiekis, int kilometrai, int tonos)
{
	Asmuo = asmuo;
	Masina = masina;
	Kiekis = kiekis;
	Kilometrai = kilometrai;
	Tonos = tonos;
}

void Duomenys::Papildyti(const Duomenys & d)
{
	Kiekis += d.Kiekis;
	Kilometrai += d.Kilometrai;
	Tonos += d.Tonos;
}

bool Duomenys::operator==(const Duomenys & kitas)
{
	return Asmuo == kitas.Asmuo && Masina == kitas.Masina;
}

bool Duomenys::operator<(const Duomenys & kitas)
{
	return Tonos < kitas.Tonos;
}
