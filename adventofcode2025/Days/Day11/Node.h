#pragma once
#include <string>
#include <vector>

class Node
{
private:
	std::string value;
	std::vector<std::string> links;
public:
	Node(std::string val);
	std::string getValue();
	std::vector<std::string>* getLinks();
	void addLink(std::string);
};