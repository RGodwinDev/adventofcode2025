// adventofcode2025.cpp : Defines the entry point for the application.
//

#include "adventofcode2025.h"

using namespace std;

int main()
{
	std::cout << "Advent of Code 2025 :)" << std::endl;

	Day1* d1 = new Day1();
	Day2* d2 = new Day2();
	Day3* d3 = new Day3();
	Day4* d4 = new Day4();
	Day5* d5 = new Day5();
	Day6* d6 = new Day6();
	Day7* d7 = new Day7();
	Day8* d8 = new Day8();
	Day9* d9 = new Day9();
	Day10* d10 = new Day10();
	Day11* d11 = new Day11();
	Day12* d12 = new Day12();
	


	auto start = std::chrono::high_resolution_clock::now();
	d1->run();
	auto d1finish = std::chrono::high_resolution_clock::now();
	d2->run();
	auto d2finish = std::chrono::high_resolution_clock::now();
	d3->run();
	auto d3finish = std::chrono::high_resolution_clock::now();
	/*
	d4->run();
	d5->run();
	d6->run();
	d7->run();
	d8->run();
	d9->run();
	d10->run();
	d11->run();
	d12->run();
	*/
	std::cout << std::endl << std::endl;
	std::cout << "RUNTIMES" << std::endl;
	std::cout << "Day 1 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d1finish - start) << std::endl;
	std::cout << "Day 2 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d2finish - d1finish) << std::endl;
	std::cout << "Day 3 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d3finish - d2finish) << std::endl;
	return 0;
}
