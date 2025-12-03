#include "./Day12.h"

void Day12::run() {

	std::string text;
	std::fstream file(input);

	while (getline(file, text)) {
		std::cout << text << std::endl;
	};




	std::cout << "Day 12: " << result1 << " " << result2 << std::endl;
}