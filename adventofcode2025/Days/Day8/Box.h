#pragma once
#include <vector>
#include <set>

class Box {
private:
	int x;
	int y;
	int z;

	std::set<Box*> connections = std::set<Box*>();
public:
	Box(int x, int y, int z);

	/// <summary>
	/// Get the position of the box
	/// </summary>
	/// <returns>Vector of positions, {x,y,z}</returns>
	std::vector<int> getPosition();
	
	bool isConnected(Box* b);
};