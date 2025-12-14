#include "Node.h"

Node::Node(std::string val) 
{
	this->value = val;
}

std::string Node::getValue() 
{
	return this->value;
}
std::vector<std::string>* Node::getLinks() 
{
	return &this->links;
}

void Node::addLink(std::string l)
{
	this->links.push_back(l);
}