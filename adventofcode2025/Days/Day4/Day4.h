#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <set>
class Day4 {
private:
	std::string input = "./day4input.txt";
	long result1 = 0;
	long result2 = 0;
	
	//v1 just checks every place in the grid, and the 8 adjacent places EVERY iteration.
	int Part1(std::vector<std::vector<char>>& grid);
	int Part2(std::vector<std::vector<char>>& grid);

	//v2 creates a graph in part 1, making part2v2 faster as we don't have to iterate over empty space everytime.
	//sadly, creating the graph takes significantly more time than the bruteforce approach of v1.
	int Part1v2(std::vector<std::vector<char>>& grid, std::map<std::pair<int, int>, std::set<std::pair<int, int>>>& graph);
	int Part2v2(std::map<std::pair<int, int>, std::set<std::pair<int,int>>>& graph);
public:
	void run();
};