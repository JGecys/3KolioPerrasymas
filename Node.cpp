#include "Node.h"



Node::Node() : pirmyn(NULL), atgal(NULL){}

Node::Node(Node * p, Node * a) : pirmyn(p), atgal(a)
{
}

Node::Node(const Duomenys& d, Node * p, Node * a) : duom(d), pirmyn(p), atgal(a)
{
}


Node::~Node()
{
}

Node & Node::operator=(const Node & kitas)
{
	if (this == &kitas)
		return *this;
	duom = kitas.duom;
	return *this;
}

bool Node::operator<(const Node & kitas)
{
	return duom < kitas.duom;
}
