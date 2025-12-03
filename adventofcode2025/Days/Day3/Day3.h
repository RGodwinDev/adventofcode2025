#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Day3 {
private:
	std::string input = "./day3input.txt";
	unsigned __int64 result1 = 0;
	unsigned __int64 result2 = 0;
public:
	void run();
	unsigned __int64 getCharge(std::string &line, int numBatteries);
};