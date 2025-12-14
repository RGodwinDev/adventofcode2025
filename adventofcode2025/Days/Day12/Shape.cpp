#include "Shape.h"

Shape::Shape(int id, std::string l1, std::string l2, std::string l3)
{
	this->id = id;
	for (char c : l1) {
		if (c == '#') {
			this->size++;
		}
	}
	for (char c : l2) {
		if (c == '#') {
			this->size++;
		}
	}
	for (char c : l3) {
		if (c == '#') {
			this->size++;
		}
	}
}


int Shape::getSize() 
{
	return this->size;
}