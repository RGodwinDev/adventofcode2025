#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "Box.h"
#include "Circuit.h"

class Day8 {
private:
	std::string input = "./day8input.txt";
	long result1 = 0;
	unsigned __int64 result2 = 0;
public:
	void run();
};