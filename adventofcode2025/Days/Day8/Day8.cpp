#include "./Day8.h"

void Day8::run() {

	std::string text;
	std::fstream file(input);

	while (getline(file, text)) {
		std::cout << text << std::endl;
	};




	std::cout << "Day 8: " << result1 << " " << result2 << std::endl;
}