#include "./Day8.h"

void Day8::run() {

	std::string text;
	std::fstream file(input);
	std::vector<Box*> boxes;

	while (getline(file, text)) {
		int a = text.find(',');
		int x = stoi(text.substr(0, a));
		int b = text.find(',', a+1);
		int y = stoi(text.substr(a+1, b-a));
		int z = stoi(text.substr(b + 1));

		boxes.push_back(new Box(x, y, z));
	};
	file.close();

	//min prio queue that contains:		pair<double, pair<box,box>>
	std::priority_queue<std::pair<double, std::pair<Box*, Box*>>, 
		std::vector<std::pair<double, std::pair<Box*, Box*>>>, 
		std::greater<std::pair<double, std::pair<Box*, Box*>>>> distances;


	for (int i = 0; i < boxes.size()-1; ++i) {
		std::vector<int> box1position = boxes[i]->getPosition();
		for (int j = i + 1; j < boxes.size(); ++j) {
			std::vector<int> box2position = boxes[j]->getPosition();

			//calc distance between the two positions https://en.wikipedia.org/wiki/Euclidean_distance
			//d(p,q) = sqrt( (p1 - q1)^2 + (p2 - q2)^2 + (p3 - q3)^2 )
			//we could remove the square root, as the actual value of distance doesnt matter
			//just that it's bigger/smaller compared to the others.
			double d = std::hypot((box1position[0] - box2position[0]), box1position[1] - box2position[1], box1position[2] - box2position[2]);

			distances.push({ d, {boxes[i], boxes[j]} });
		}
	}
	
	
	std::set<Circuit*> circuits = std::set<Circuit*>();

	int i = 0;
	while (i < 1000) {
		std::vector<Circuit*> a;
		for (Circuit* c : circuits) {
			if (c->containsBox(distances.top().second.first)) {
				a.push_back(c);
			}
			if (c->containsBox(distances.top().second.second)) {
				a.push_back(c);
			}
		}
		if (a.size() > 0) { //at least 1 box was in a circuit.
			Circuit* main = a[0];
			for (int i = 1; i < a.size(); ++i) {
				main->merge(a[i]);
				circuits.erase(a[i]);
			}
			main->insertBox(distances.top().second.first);
			main->insertBox(distances.top().second.second);

			//main circuit might have been erased if both were in it.
			circuits.insert(main);
		}
		else {
			//boxes werent in any circuit, create a new one.
			Circuit* c = new Circuit();
			c->insertBox(distances.top().second.first);
			c->insertBox(distances.top().second.second);
			circuits.insert(c);
		}
		i++;
		distances.pop();
	}
	
	int largest = 0;
	int larger = 0;
	int large = 0;
	for (Circuit* c : circuits) {
		int cSize = c->getSize();
		if (cSize > largest) {
			large = larger;
			larger = largest;
			largest = cSize;
		}
		else if (cSize > larger) {
			large = larger;
			larger = cSize;
		}
		else if (cSize > large) {
			large = cSize;
		}
	}
	result1 = large * larger * largest;


	/*
	*		PART 2:
	*		Keep connecting boxes until all the boxes are in a single circuit
	*/

	unsigned __int64 prevx1 = 0;
	unsigned __int64 prevx2 = 0;
	double lastdist = 0;
	//while we have more than 1 circuit.
	//there 'could' be boxes that still exist outside the circuit that have NO connection.
	while (circuits.size() > 1 && i < distances.size()) {
		prevx1 = distances.top().second.first->getPosition()[0];
		prevx2 = distances.top().second.second->getPosition()[0];
		lastdist = distances.top().first;
		std::vector<Circuit*> a;
		for (Circuit* c : circuits) {

			//if a circuit contains either box, add it to the circuit vector.
			if (c->containsBox(distances.top().second.first))
			{
				a.push_back(c);
			}
			if (c->containsBox(distances.top().second.second))
			{
				a.push_back(c);
			}
		}
		if (a.size() > 0) 
		{	
			//at least 1 box was in a circuit.
			Circuit* main = a[0];
			for (int i = 1; i < a.size(); ++i) { //merge all the circuits into the main one.
				main->merge(a[i]);
				circuits.erase(a[i]);
			}

			main->insertBox(distances.top().second.first);
			main->insertBox(distances.top().second.second);

			//main circuit might have been erased if both were in it.
			circuits.insert(main);
		}
		else 
		{
			//boxes werent in any circuit, create a new one.
			Circuit* c = new Circuit();
			c->insertBox(distances.top().second.first);
			c->insertBox(distances.top().second.second);
			circuits.insert(c);
		}
		i++;
		distances.pop();
	}

	result2 = prevx1 * prevx2;


	std::cout << "Day 8: " << result1 << " " << result2 << std::endl;
}