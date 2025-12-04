#include "./Day4.h"

void Day4::run() {

	std::string text;
	std::fstream file(input);

	//rolls can be accessed IF there are fewer than 4 adjacent rolls.
	//8 cardinal directions: n e s w ne se sw nw
	// 
	// part 1:
	//		how many rolls are accessible?
	// part 2:
	//		remove accessible rolls until there are no more accessible rolls.
	//		how many got removed?

	std::vector<std::vector<char>> grid;

	while (getline(file, text)) {
		std::vector<char> line;
		for (size_t i = 0; i < text.size(); ++i) {
			line.push_back(text[i]);
		}
		grid.push_back(line);
	};
	
	//VERSION 1
	result1 = Part1(grid);
	result2 = Part2(grid);
	
	/* VERSION 2
	std::map<std::pair<int, int>, std::set<std::pair<int, int>>> graph;
	result1 = Part1v2(grid, graph);
	result2 = Part2v2(graph);
	*/
	std::cout << "Day 4: " << result1 << " " << result2 << std::endl;
}

//count how many rolls are accessible
int Day4::Part1(std::vector<std::vector<char>>& grid) {
	int accessibleRolls = 0;
	for (size_t i = 0; i < grid.size(); ++i) {
		for (size_t j = 0; j < grid[i].size(); ++j) {
			if (grid[i][j] == '@') {
				int countAdjacent = 0;

				if (i > 0) { //north
					if (j > 0) { //nw
						countAdjacent += grid[i - 1][j - 1] == '@';
					}
					countAdjacent += grid[i - 1][j] == '@'; //north north
					if (j < grid[i].size() - 1) { //ne
						countAdjacent += grid[i - 1][j + 1] == '@';
					}
				}
				if (j > 0) { //ww
					countAdjacent += grid[i][j - 1] == '@';
				}
				if (j < grid[i].size() - 1) { //east east
					countAdjacent += grid[i][j + 1] == '@';
				}
				if (i < grid.size() - 1) { //south
					if (j > 0) { //sw
						countAdjacent += grid[i + 1][j - 1] == '@';
					}
					countAdjacent += grid[i + 1][j] == '@'; //south south
					if (j < grid[i].size() - 1) { //se
						countAdjacent += grid[i + 1][j + 1] == '@';
					}
				}
				accessibleRolls += countAdjacent < 4;
			}
		}
	}
	return accessibleRolls;
}

/// <summary>
///		Remove all accessible rolls from the grid.
/// </summary>
/// <param name="grid">Grid you want rolls removed from.</param>
/// <returns>Number of rolls removed from the grid.</returns>
int Day4::Part2(std::vector<std::vector<char>> &grid) {
	int changeSum = 0;
	int changes = 1;
	while (changes) {
		changes = 0;
		for (size_t i = 0; i < grid.size(); ++i) {
			for (size_t j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == '@') {
					int countAdjacent = 0;

					if (i > 0) { //north
						if (j > 0) { //nw
							countAdjacent += grid[i - 1][j - 1] == '@';
						}
						countAdjacent += grid[i - 1][j] == '@'; //north north
						if (j < grid[i].size() - 1) { //ne
							countAdjacent += grid[i - 1][j + 1] == '@';
						}
					}
					if (j > 0) { //ww
						countAdjacent += grid[i][j - 1] == '@';
					}
					if (j < grid[i].size() - 1) { //east east
						countAdjacent += grid[i][j + 1] == '@';
					}
					if (i < grid.size() - 1) { //south
						if (j > 0) { //sw
							countAdjacent += grid[i + 1][j - 1] == '@';
						}
						countAdjacent += grid[i + 1][j] == '@'; //south south
						if (j < grid[i].size() - 1) { //se
							countAdjacent += grid[i + 1][j + 1] == '@';
						}
					}
					if (countAdjacent < 4) {
						grid[i][j] = '.';
						changes++;
					}
				}
			}
		}
		changeSum += changes;
	}
	return changeSum;
}

/*
		VERSION 2:
		Create a graph of the rolls in part 1.
		Now we only have to iterate over rolls in part 2.
		Skipping empty floor.

		Creating the graph made this ~10x slower than version 1.
		It did make part 2 faster.
*/


/// <summary>
/// Count the amount of accessible rolls and create a graph of the rolls.
/// </summary>
/// <param name="grid">Grid of rolls to be counted.</param>
/// <param name="graph"></param>
/// <returns>Number of rolls that are accessible.</returns>
int Day4::Part1v2(std::vector<std::vector<char>>& grid, std::map<std::pair<int, int>, std::set<std::pair<int, int>>>& graph) {

	for (size_t i = 0; i < grid.size(); i++) {
		for (size_t j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == '@') {

				//this line initializes the position in the graph.
				//needed for cases where there are NO adjacent '@'.
				graph[{i, j}];

				if (j < grid[i].size() - 1
					&& grid[i][j + 1] == '@') { //east east

					graph[{i, j}].insert({ i, j + 1 });
					graph[{i, j + 1}].insert({ i,j });
				}

				if (i < grid.size() - 1) { //south
					if (j > 0
						&& grid[i + 1][j - 1] == '@') { //south west

						graph[{i, j}].insert({ i + 1, j - 1 });
						graph[{i + 1, j - 1}].insert({ i, j });
					}

					if (grid[i + 1][j] == '@') { //south south

						graph[{i, j}].insert({ i + 1, j });
						graph[{i + 1, j}].insert({ i, j });
					}

					if (j < grid[i].size() - 1
						&& grid[i + 1][j + 1] == '@') { //south east

						graph[{i, j}].insert({ i + 1, j + 1 });
						graph[{i + 1, j + 1}].insert({ i, j });
					}
				}
			}
		}
	}
	int accessibleRolls = 0;
	for (auto g : graph) {
		accessibleRolls += g.second.size() < 4;
	}
	return accessibleRolls;
}

/// <summary>
///		Remove accessible rolls from the graph.
/// </summary>
/// <param name="graph">The graph you want the rolls removed from.</param>
/// <returns>Number of rolls removed.</returns>
int Day4::Part2v2(std::map<std::pair<int, int>, std::set<std::pair<int, int>>>& graph) {
	int startSize = graph.size();
	
	int changes = 1;
	while (changes) {
		changes = 0;
		auto g = graph.begin();

		while (g != graph.end()) {
			std::pair<int, int> x = g->first;
			if (g->second.size() < 4) {
				for (std::pair<int, int> p : g->second) {
					graph[p].erase(g->first);
				}
				changes++;
				g++; //advance to next BEFORE erasing.
				graph.erase(x);
			}
			else {
				g++;
			}
		}
	} 
	

	int endSize = graph.size();
	return startSize - endSize;
}