#include "Path.h"

Path::Path(Node* next)
{
	this->nextNode = next;
}

bool Path::pass()
{
	return fft && dac;
}

Node* Path::getNode()
{
	return this->nextNode;
}