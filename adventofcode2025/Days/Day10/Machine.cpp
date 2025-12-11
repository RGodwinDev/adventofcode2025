#include "Machine.h"

Machine::Machine(std::string m) 
{
	//get the goal
	int g = 0;
	int goalSize = 0;
	for (int i = 0; i < m.size(); ++i) 
	{
		if (m[i] == '.') {
			g *= 2;
		}
		else if (m[i] == '#') {
			g *= 2;
			g++;
		}
		else if (m[i] == ']') {
			break;
		}
		goalSize++;
	}

	//flip the goal
	int h = 0;
	while (goalSize-1 > 0) 
	{
		h *= 2;
		h += g % 2;
		g /= 2;
		goalSize--;
	}
	this->goal = h;

	//create buttons
	int left = m.find('(');
	while (left > -1) {
		std::string b = m.substr(left+1, m.find(')', left) - (left+1));
		this->Buttons.push_back(new Button(b));
		left = m.find('(', left + 1);
	}

	//get the joltage
	this->j = Joltage(m.substr(m.find('{')));

}

int Machine::calcShortestPath() {
	std::set<int> values;
	int presses = 1;
	for (int i = 0; i < Buttons.size(); ++i) 
	{
		if (Buttons[i]->getVal() == goal) { //we only have to press that button!
			return presses;
		}
		values.insert(Buttons[i]->getVal());
	}
	while (true) {
		presses++;
		std::set<int> values2;
		for (Button* b : this->Buttons) {
			for (int v : values) {
				int g = b->getVal() ^ v;
				if (g == goal) {
					return presses;
				}
				values2.insert(g);
			}
		}
		values = values2;
	}
	return -1;
}