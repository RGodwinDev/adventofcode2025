#include "./Day6.h"

void Day6::run() {

	std::string text;
	std::fstream file(input);

	while (getline(file, text)) {
		std::cout << text << std::endl;
	};




	std::cout << "Day 6: " << result1 << " " << result2 << std::endl;
}