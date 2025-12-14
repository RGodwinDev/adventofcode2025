#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#include "Node.h"
#include "Path.h"

class Day11 {
private:
	std::string input = "./day11input.txt";
	__int64 result1 = 0;
	__int64 result2 = 0;
public:
	void run();
};