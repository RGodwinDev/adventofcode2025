#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>

class Day2 {
private:
	std::string input = "./day2input.txt";
	unsigned __int64 result1 = 0;
	unsigned __int64 result2 = 0;
public:
	void run();
	unsigned __int64 calc(std::unordered_set<unsigned __int64>& numbers, unsigned __int64 min, unsigned __int64 max, int leftsize, int digitsmin, int digitsmax);
};