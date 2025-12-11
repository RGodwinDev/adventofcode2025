#include "./Day10.h"

void Day10::run() {

	std::string text;
	std::fstream file(input);

	std::vector<Machine*> machines;

	while (getline(file, text)) 
	{
		machines.push_back(new Machine(text));
	};

	for (Machine* m : machines) 
	{
		result1 += m->calcShortestPath();
	}

	std::cout << "Day 10: " << result1 << " " << result2 << std::endl;
}