#include "day1.h"

/// <summary>
/// Run Day1!
/// </summary>
void Day1::run() {

	std::string text;
	std::fstream file(input);

	int curVal = 50;
	while (getline(file, text)) {
		if (text[0] == 'L') {
			curVal = turnleft(curVal, stoi(text.substr(1)));
		}
		else {
			curVal = turnright(curVal, stoi(text.substr(1)));
		}
		if (curVal == 0) {
			result1++;
		}
	}
	std::cout << "Day 1: " << result1 << " " << result2 << std::endl;
}

int Day1::turnleft(int start, int ticks) {
	int t = start;
	if (t == 0) { t = 100; }

	if (ticks >= t) { //ticks will go under 0 at least once.
		result2 += ((ticks - t) / 100) + 1; //difference / 100, add 1
	}

	return (((start - ticks) % 100) + 100) % 100;
}


int Day1::turnright(int start, int ticks) {
	result2 += (start + ticks) / 100;
	return (((start + ticks) % 100) + 100) % 100;
}
