#include "./Day9.h"

void Day9::run() {

	std::string text;
	std::fstream file(input);

	while (getline(file, text)) {
		std::cout << text << std::endl;
	};




	std::cout << "Day 9: " << result1 << " " << result2 << std::endl;
}