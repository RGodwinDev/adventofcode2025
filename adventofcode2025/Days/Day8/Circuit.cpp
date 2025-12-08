#include "Circuit.h"

Circuit::Circuit()
{

}

bool Circuit::containsBox(Box* b)
{
	return this->circuit.contains(b);
}

void Circuit::merge(Circuit* c)
{
	//merging with self be redundant.
	if (c == this) { return; }

	for (Box* b : *c->getBoxes()) {
		this->insertBox(b);
	}
}

void Circuit::insertBox(Box* b) {
	this->circuit.insert(b);
}

std::set<Box*>* Circuit::getBoxes() {
	return &this->circuit;
	//is it possible to limit to same class call only?
}

int Circuit::getSize() {
	return this->circuit.size();
}