#include "Box.h"

Box::Box(int x, int y, int z) 
{
	this->x = x;
	this->y = y;
	this->z = z;
}

std::vector<int> Box::getPosition()
{
	return { this->x, this->y, this->z };
}

bool Box::isConnected(Box* b)
{
	return this->connections.contains(b);
}