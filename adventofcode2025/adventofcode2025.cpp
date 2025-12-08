// adventofcode2025.cpp : Defines the entry point for the application.
//

#include "adventofcode2025.h"

using namespace std;

/// <summary>
/// Advent of Code 2025!
/// https://adventofcode.com/2025/
/// </summary>
/// <returns></returns>
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
	d1->run(100, 50);
	auto d1finish = std::chrono::high_resolution_clock::now();
	d2->run();
	auto d2finish = std::chrono::high_resolution_clock::now();
	d3->run();
	auto d3finish = std::chrono::high_resolution_clock::now();
	d4->run();
	auto d4finish = std::chrono::high_resolution_clock::now();
	d5->run();
	auto d5finish = std::chrono::high_resolution_clock::now();
	d6->run();
	auto d6finish = std::chrono::high_resolution_clock::now();
	d7->run();
	auto d7finish = std::chrono::high_resolution_clock::now();
	d8->run();
	auto d8finish = std::chrono::high_resolution_clock::now();
	//d9->run();
	auto d9finish = std::chrono::high_resolution_clock::now();
	//d10->run();
	auto d10finish = std::chrono::high_resolution_clock::now();
	//d11->run();
	auto d11finish = std::chrono::high_resolution_clock::now();
	//d12->run();
	auto d12finish = std::chrono::high_resolution_clock::now();

	std::cout << std::endl << std::endl;
	std::cout << "RUNTIMES" << std::endl;
	std::cout << "Day 1 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d1finish - start) << std::endl;
	std::cout << "Day 2 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d2finish - d1finish) << std::endl;
	std::cout << "Day 3 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d3finish - d2finish) << std::endl;
	std::cout << "Day 4 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d4finish - d3finish) << std::endl;
	std::cout << "Day 5 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d5finish - d4finish) << std::endl;
	std::cout << "Day 6 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d6finish - d5finish) << std::endl;
	std::cout << "Day 7 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d7finish - d6finish) << std::endl;
	std::cout << "Day 8 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d8finish - d7finish) << std::endl;
	std::cout << "Day 9 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d9finish - d8finish) << std::endl;
	std::cout << "Day 10 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d10finish - d9finish) << std::endl;
	std::cout << "Day 11 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d11finish - d10finish) << std::endl;
	std::cout << "Day 12 took: " << std::chrono::duration_cast<std::chrono::microseconds>(d12finish - d11finish) << std::endl;
	std::cout << "Total: " << std::chrono::duration_cast<std::chrono::microseconds>(d12finish - start) << std::endl;
	return 0;
}
