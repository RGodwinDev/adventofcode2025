#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Day1 {
private:
	std::string input = "./day1input.txt";
	int result1 = 0;
	int result2 = 0;
	int turnleft(int start, int ticks);
	int turnright(int start, int ticks); 
public:
	void run();
};