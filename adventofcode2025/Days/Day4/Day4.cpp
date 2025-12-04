#include "./Day4.h"

void Day4::run() {

	std::string text;
	std::fstream file(input);

	//rolls can be accessed IF there are fewer than 4 adjacent rolls.
	//8 cardinal directions: n e s w ne se sw nw
	// 
	// part 1
	//how many rolls can be accessed?

	std::vector<std::vector<char>> grid;
	

	while (getline(file, text)) {
		std::vector<char> line;
		for (size_t i = 0; i < text.size(); ++i) {
			line.push_back(text[i]);
		}
		grid.push_back(line);
	};
	
	result1 = Part1(grid);
	result2 = Part2(grid);
	
	/*
	std::map<std::pair<int, int>, std::set<std::pair<int, int>>> graph;
	result1 = Part1v2(grid, graph);
	result2 = Part2v2(graph);
	*/
	std::cout << "Day 4: " << result1 << " " << result2 << std::endl;
}
int Day4::Part1(std::vector<std::vector<char>>& grid) {
	int changes = 0;
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
					changes++;
				}
			}
		}
	}
	return changes;
}


int Day4::Part1v2(std::vector<std::vector<char>>& grid, std::map<std::pair<int, int>, std::set<std::pair<int, int>>> &graph) {
	
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
	int accessibleRollCount = 0;
	for (auto g : graph) {
		accessibleRollCount += g.second.size() < 4;
	}
	return accessibleRollCount;
}

//same as part 1, 
//but remove accessable rolls and 
//check for newly accessable rolls 
//until we cant access any rolls.
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