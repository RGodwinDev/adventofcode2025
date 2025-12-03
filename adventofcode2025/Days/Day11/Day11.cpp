#include "./Day11.h"

void Day11::run() {

	std::string text;
	std::fstream file(input);

	while (getline(file, text)) {
		std::cout << text << std::endl;
	};




	std::cout << "Day 11: " << result1 << " " << result2 << std::endl;
}