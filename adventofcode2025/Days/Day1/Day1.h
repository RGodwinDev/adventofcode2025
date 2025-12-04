#pragma once
#include <iostream>
#include <string>
#include <fstream>

/// <summary>
/// Day 1 of Advent of Code 2025
/// https://adventofcode.com/2025/day/1
/// </summary>
class Day1 {
private:
	std::string input = "./day1input.txt";
	int result1 = 0;
	int result2 = 0;
	int turnleft(int start, int ticks);
	int turnright(int start, int ticks); 
public:
	void run(int dialSize, int startPos);
};