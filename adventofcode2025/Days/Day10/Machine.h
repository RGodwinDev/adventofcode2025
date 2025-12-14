#pragma once
#include "Joltage.h"
#include "Button.h"
#include <string>
#include <map>
#include <set>

class Machine 
{
private:
	Joltage j;
	std::vector<Button*> Buttons;
	int goal = 0;
public:
	Machine(std::string m);
	int calcShortestPath();
};