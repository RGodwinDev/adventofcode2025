#include "./Day6.h"

void Day6::run() {

	std::string text;
	std::fstream file(input);
	std::vector<std::vector<unsigned __int64>> Problems;


	while (getline(file, text) && text[0] != '+' && text[0] != '*') {
		std::stringstream ss(text);
		std::string token;
		std::vector<unsigned __int64> numbers;
		while (ss >> token) {
			
			numbers.push_back(stoll(token));
		}
		Problems.push_back(numbers);
	};

	std::stringstream ss(text);
	std::string token;
	int i = 0;
	int multiplies = 0;
	int adds = 0;
	while (ss >> token) {
		if (token[0] == '*') {
			unsigned __int64 sum = 1;
			for (int j = 0; j < Problems.size(); ++j) {
				sum *= Problems[j][i];
			}
			result1 += sum;
		}
		else { //add
			unsigned __int64 sum = 0;
			for (int j = 0; j < Problems.size(); ++j) {
				sum += Problems[j][i];
			}
			result1 += sum;
		}
		++i;
	}

	file.clear(); //clear any flags on the file.
	file.seekg(0); //reset the fstream to the start of the file.
	/*
	std::vector<std::string> lines;
	while (std::getline(file, text) && text[0] != '+' && text[0] != '*') {
		lines.push_back(text);
		std::cout << text << std::endl;
	}
	//std::cout << "numbers finished" << std::endl;
	//std::cout << text << std::endl;  


	std::vector<std::string> numbers;
	for (int j = 0; j < lines[0].size(); ++j) {
		
		for (int i = 0; i < lines.size(); ++i) {

		}
		if (numbers[numbers.size() - 1] == "") {
			//we are on a blank line
		}
	}


	*/



	std::cout << "Day 6: " << result1 << " " << result2 << std::endl;
}