#pragma once
#include <vector>

class Box {
private:
	int x;
	int y;
	int z;

public:
	Box(int x, int y, int z);

	/// <summary>
	/// Get the position of the box
	/// </summary>
	/// <returns>Vector of positions, {x,y,z}</returns>
	std::vector<int> getPosition();
};