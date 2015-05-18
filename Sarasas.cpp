#include "Sarasas.h"



void Sarasas::Naikinti()
{
	Node *n = NULL;
	while (pr) {
		n = pr;
		pr = pr->Pirmyn();
		delete n;
	}
}

Sarasas::Sarasas()
{
	pr = new Node();
	pb = new Node(NULL, pr);
	pr->DetiPirmyn(pb);
}


Sarasas::~Sarasas()
{
	Naikinti();
}

void Sarasas::Prideti(const Duomenys & d)
{
	Node* pries = pb->Atgal();
	Node* naujas = new Node(d, pb, pries);
	pries->DetiPirmyn(naujas);
	pb->DetiAtgal(naujas);
}

void Sarasas::Isvalyti()
{
	if (Tuscias())
		return;
	Node* n = NULL, *m = pr->Pirmyn();
	while (m->Pirmyn() != NULL) {
		n = m;
		m = m->Pirmyn();
		delete n;
	}
	pr->DetiPirmyn(pb);
	pb->DetiAtgal(pr);
}

bool Sarasas::Rasti(const Duomenys & d)
{
	for (Pradzia(); NePabaiga(); EitiPirmyn()) {
		if (Imti() == d)
			return true;
	}
	return false;
}

void Sarasas::Papildyti(Sarasas & p)
{
	for (p.Pradzia(); p.NePabaiga(); p.EitiPirmyn()) {
		if (Rasti(p.Imti())) {
			dd->Duom().Papildyti(p.Imti());
		}
		else {
			Prideti(p.Imti());
		}
	}
}

bool Sarasas::MaziausiaiPerveze(Duomenys & maz)
{
	if (Tuscias())
		return false;
	maz = pr->Pirmyn()->Duom();
	for (dd = pr->Pirmyn()->Pirmyn(); dd->Pirmyn() != NULL; dd = dd->Pirmyn()) {
		if (dd->Duom() < maz)
			maz = dd->Duom();
	}
	return true;
}

Sarasas & Sarasas::operator=(Sarasas & kitas)
{
	if (this == &kitas)
		return *this;
	Isvalyti();
	for (kitas.Pradzia(); kitas.NePabaiga(); kitas.EitiPirmyn()) {
		Prideti(kitas.Imti());
	}
	return *this;
}
