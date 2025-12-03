#include "./Day5.h"

void Day5::run() {

	std::string text;
	std::fstream file(input);

	while (getline(file, text)) {
		std::cout << text << std::endl;
	};




	std::cout << "Day 5: " << result1 << " " << result2 << std::endl;
}