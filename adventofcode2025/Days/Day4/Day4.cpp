#include "./Day4.h"

void Day4::run() {

	std::string text;
	std::fstream file(input);

	while (getline(file, text)) {
		std::cout << text << std::endl;
	};




	std::cout << "Day 4: " << result1 << " " << result2 << std::endl;
}