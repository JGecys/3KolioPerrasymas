#include "Sarasas.h"

#include <fstream>
#include <iomanip>

const string CDuom = "Duomenys.txt";
const string CDuomPap = "Papildymas.txt";
const string CRez = "Rezultatai.txt";

void Nuskaityti(Sarasas & S, const string & file);

int main() {
	Sarasas *R1 = new Sarasas();
	Nuskaityti(*R1, CDuom); //Nuskaito Duomenys.txt

	Sarasas *R2 = new Sarasas();
	Nuskaityti(*R2, CDuomPap); //Nuskato Papildymas.txt

	Sarasas *R3 = new Sarasas();
	*R3 = *R1; //Naudoja priskyrimo operatoriu
	R3->Papildyti(*R2); //Papildo Sarasa elementais is R2

	Duomenys MaziausiaiPerveze;
	if (R3->MaziausiaiPerveze(MaziausiaiPerveze)) {
		//Jei rado
	}
	else {
		//Jei Sarasas Tuscias
	}
	//Spausdinimas


	delete R1, R2, R3;
	return 0;
}

void Nuskaityti(Sarasas & S, const string & file) {
	ifstream f(file);

	string a, m;
	int k, km, t;

	while (!f.eof()) {
		getline(f, a, ','); f >> ws;
		getline(f, m, ',');
		f >> k >> km >> t;
		f.ignore(80, '\n');
		S.Prideti(Duomenys(a, m, k, km, t));
	}
	f.close();
}