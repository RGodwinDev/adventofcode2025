#include "./Day3.h"

void Day3::run() {

	std::string text;
	std::fstream file(input);

	while (getline(file, text)) {
		result1 += getCharge(text, 2);
		result2 += getCharge(text, 12);
	};
	file.close();
	std::cout << "Day 3: " << result1 << " " << result2 << std::endl;
}

unsigned __int64 Day3::getCharge(std::string &line, int numBatteries) {
	int lsize = line.size()-1;
	std::vector<int> places = {-1};

	for (int b = numBatteries-1; b >= 0; b--) {
		char largest = '0';
		for (int i = places[places.size() - 1]+1; i <= lsize - b; i++) {
			if (line[i] > largest)
			{
				largest = line[i];
				places[places.size()-1] = i;
			}
		}
		places.push_back(places[places.size()-1]);
	}
	
	std::string sum = "";
	for (int j = 0; j < places.size()-1; j++) {
		sum += line[places[j]];
	}

	return stoll(sum);
}