#include "./Day9.h"

void Day9::run() 
{
	std::string text;
	std::fstream file(input);

	std::vector<std::pair<__int64, __int64>> redTiles;
	while (getline(file, text)) 
	{
		int c = text.find(',');
		__int64 x = stoll(text.substr(0, c));
		__int64 y = stoll(text.substr(c+1));
		redTiles.push_back({ x,y });
	};

	__int64 result1 = 0;

	//check all possible squares
	for (int i = 0; i < redTiles.size()-1; ++i) 
	{
		for (int j = i + 1; j < redTiles.size(); ++j) 
		{
			result1 = std::max(result1,
				(abs(redTiles[i].first - redTiles[j].first)+1) 
				* (abs(redTiles[i].second - redTiles[j].second)+1));

		}
	}

	//part 2:
	//a square can only include red or green tiles (not both)
	//every red tile is connected to the red tile before and after it by a line of green tiles
	//connect the dots.
	//connected tiles are always on the same row or column. (no diagonal green lines).
	//all tiles inside the loop are also green.
	//the rectangle still has 2 opposing red corners.
	

	std::cout << "Day 9: " << result1 << " " << result2 << std::endl;
}