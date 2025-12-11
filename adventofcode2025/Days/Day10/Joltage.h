#pragma once
#include <vector>
#include <string>

class Joltage {
private:
	std::vector<int> jolts;
public:
	Joltage();
	Joltage(std::string s);
};