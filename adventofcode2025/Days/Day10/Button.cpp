#include "Button.h"

Button::Button(std::string b) 
{
	int total = 0;
	int left = b.find(',') + 1;
	std::string c = b;

	while (left > 0)
	{
		int x = stoi(c);
		total += pow(2, x);
		c = b.substr(left);
		left = b.find(',', left + 1) + 1;
	}

	total += pow(2, stoi(c));
	this->b = total;
}

int Button::getVal()
{
	return this->b;
}