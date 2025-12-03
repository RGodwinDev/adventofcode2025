#include "./Day10.h"

void Day10::run() {

	std::string text;
	std::fstream file(input);

	while (getline(file, text)) {
		std::cout << text << std::endl;
	};




	std::cout << "Day 10: " << result1 << " " << result2 << std::endl;
}