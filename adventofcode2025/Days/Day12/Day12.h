#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Shape.h"

class Day12 {
private:
	std::string input = "./day12input.txt";
	long result1 = 0;
	std::string result2 = "Merry Christmas :)";
public:
	void run();
	bool fits(std::string t, std::vector<Shape*>& shapes);
};