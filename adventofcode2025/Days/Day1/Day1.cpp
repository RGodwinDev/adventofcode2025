#include "day1.h"

/// <summary>
/// Run Day1!
/// </summary>
void Day1::run(int dialSize, int startPos) {

	std::string text;
	std::fstream file(input);
	
	//There is a dial that starts at 50
	//The dial has numbers between 0 and 99.
	int curVal = startPos; //could add a variable for starting position in the function call.

	//Each line from the input is either L## or R##,
	//indicating how many times we turn the dial left or right.
	//part 1 = how many times the dial is at 0 after spinning each time.
	//part 2 = how many times the dial touches 0, even while spinning.
	while (getline(file, text)) {

		if (text[0] == 'L') {
			curVal = turnleft(curVal, stoi(text.substr(1)));
		}
		else {
			curVal = turnright(curVal, stoi(text.substr(1)));
		}

		//if the dial is resting at zero, increase result1.
		if (curVal == 0) { result1++; }
	}

	file.close();
	std::cout << "Day 1: " << result1 << " " << result2 << std::endl;
}

/// <summary>
/// Turn the dial to the Left.
/// </summary>
/// <param name="start">Starting position of the Dial.</param>
/// <param name="ticks">How many ticks to turn the Dial Left.</param>
/// <returns>int position of the Dial after turning.</returns>
int Day1::turnleft(int start, int ticks) {
	int t = start;
	if (t == 0) { t = 100; }

	//ticks will go under 0 at least once.
	//increase result2 for each time 0 is crossed.
	if (ticks >= t) {
		result2 += ((ticks - t) / 100) + 1; //difference / 100, add 1
	}

	return (((start - ticks) % 100) + 100) % 100;
}

/// <summary>
/// Turn the dial to the Right.
/// </summary>
/// <param name="start">Starting position of the Dial.</param>
/// <param name="ticks">How many ticks to turn the Dial Right.</param>
/// <returns>int position of the Dial after turning.</returns>
int Day1::turnright(int start, int ticks) {

	//increase result2 for each time 0 is crossed.
	result2 += (start + ticks) / 100;
	return (((start + ticks) % 100) + 100) % 100;
}
