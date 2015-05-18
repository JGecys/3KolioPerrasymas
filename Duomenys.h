#pragma once
#include <string>

using namespace std;

class Duomenys
{
	string Asmuo, Masina;
	int Kiekis, Kilometrai, Tonos;
public:
	Duomenys();
	Duomenys(string a, string m, int k, int km, int t);
	~Duomenys();
	void Imti(string & asmuo, string & masina, int & kiekis, int & kilometrai, int & tonos);
	void Deti(string asmuo, string masina, int kiekis, int kilometrai, int tonos);

	void Papildyti(const Duomenys& d);

	bool operator ==(const Duomenys& kitas);
	bool operator <(const Duomenys& kitas);
};

