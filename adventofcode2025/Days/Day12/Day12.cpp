#include "./Day12.h"

void Day12::run() {

	std::string text;
	std::fstream file(input);

	std::vector<Shape*> shapes;

	//get shapes
	int i = 0;
	while (i < 6) {
		getline(file, text);
		int id = stoi(text);
		getline(file, text);
		std::string l1 = text;
		getline(file, text);
		std::string l2 = text;
		getline(file, text);
		std::string l3 = text;
		getline(file, text);
		shapes.push_back(new Shape(id, l1, l2, l3));
		++i;
	}

	while (getline(file, text)) {
		result1 += fits(text, shapes);
	};

	std::cout << "Day 12: " << result1 << " " << result2 << std::endl;
}


bool Day12::fits(std::string t, std::vector<Shape*> &shapes) {
	int x = stoi(t.substr(0, 2));
	int y = stoi(t.substr(3, 2));
	if (x < 3 || y < 3) { return false; } //no shape can fit a space thats under 3x3.
	//6 shapes
	int acount = stoi(t.substr(7, 2));
	int bcount = stoi(t.substr(10, 2));
	int ccount = stoi(t.substr(13, 2));
	int dcount = stoi(t.substr(16, 2));
	int ecount = stoi(t.substr(19, 2));
	int fcount = stoi(t.substr(22, 2));

	int minarea = 0;
	minarea += acount * shapes[0]->getSize();
	minarea += bcount * shapes[1]->getSize();
	minarea += ccount * shapes[2]->getSize();
	minarea += dcount * shapes[3]->getSize();
	minarea += ecount * shapes[4]->getSize();
	minarea += fcount * shapes[5]->getSize();
	int area = x * y;
	int totalshapes = acount + bcount + ccount + dcount + ecount + fcount;

	if (area < minarea)				//won't be able to fit no matter how we do the shapes.
	{
		return false;
	}
	if (area >= totalshapes * 9)	//fits no matter how we orient the shapes.
	{ 
		return true;
	}
	//do math to figure out fitting the shapes into the area
	//the input was easy enough, this was all we needed...
	

	//https://www.reddit.com/r/adventofcode/comments/1pl6n0n/2025_day_12_part_1_i_was_pondering_over_the/
	//has a paper by Donald Knuth that introduces the DLX algorithm
	//https://arxiv.org/pdf/cs/0011047
	//https://isomerdesign.com/Pentomino/index.html pentomino puzzle.

	return false;
}
