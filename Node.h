#pragma once
#include "Duomenys.h"

class Node
{
	Duomenys duom;
	Node	*pirmyn,
			*atgal;
public:
	Node();
	Node(Node * p, Node * a);
	Node(const Duomenys& d, Node * p = NULL, Node * a = NULL);
	~Node();
	Node* Pirmyn() { return pirmyn; }
	Node* Atgal() { return atgal; }
	void DetiPirmyn(Node* p) { pirmyn = p; }
	void DetiAtgal(Node* a) { atgal = a; }
	Duomenys& Duom() { return duom; }

	Node& operator =(const Node& kitas);
	bool operator <(const Node& kitas);
};

