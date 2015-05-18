#pragma once
#include "Node.h"

class Sarasas
{
	Node *pr, *pb, *dd;
	void Naikinti();
	Sarasas(Sarasas& k);
public:
	Sarasas();
	~Sarasas();
	void Prideti(const Duomenys& d);
	void Pradzia() { dd = pr->Pirmyn(); }
	void Pabaiga() { dd = pb->Atgal(); }
	bool NePabaiga() { return dd->Atgal() != NULL && dd->Pirmyn() != NULL; }
	void EitiPirmyn() { dd = dd->Pirmyn(); }
	void EitiAtgal() { dd = dd->Atgal(); }
	Duomenys Imti() { return dd->Duom(); }
	void Deti(const Duomenys& d) { dd->Duom() = d; }
	bool Tuscias() { return pr->Pirmyn()->Pirmyn() == NULL; }
	void Isvalyti();

	bool Rasti(const Duomenys& d);
	void Papildyti(Sarasas& p);

	bool MaziausiaiPerveze(Duomenys& maz);

	Sarasas& operator =(Sarasas& kitas);
};

