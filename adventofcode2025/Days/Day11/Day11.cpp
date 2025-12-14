#include "./Day11.h"

void Day11::run() 
{
	std::string text;
	std::fstream file(input);

	std::map<std::string, std::set<std::string>> m;
	std::map<std::string, Node*> nodes;

	while (getline(file, text)) 
	{
		std::stringstream ss(text);
		std::string word = "";
		ss >> word;
		std::string a = word.substr(0, 3);
		
		Node* n = new Node(a);
		while (ss >> word) 
		{
			n->addLink(word);
			m[a].insert(word);
		}
		nodes[a] = n; //doing it this way, assuming theres no duplicate nodes.
	};


	//Part 1: BFS or DFS are easy enough
	//start with 'you'
	__int64 count = 0;
	std::queue<std::string> q;
	q.push("you");
	//std::set<std::string> discovered;
	//discovered.insert("you");

	while (!q.empty()) 
	{
		std::string cur = q.front();
		q.pop();
		std::set<std::string> vals = m[cur];
		for (std::string v : vals) 
		{
			if (v == "out") 
			{ 
				count++; 
			}
			else //if(!discovered.contains(v)) 
			{
				q.push(v);
				//discovered.insert(v);
			}
		}
	}
	result1 = count;
	//part 1 done:
	//It's just brute forcing all the routes, but it still runs in only 1.5ms.
	//ways to optimize: create 'nodes' and give them values, and calculate to remove a lot of redundant work.

	//		PART 2
	//		calc paths that start at 'svr' and end at 'out'
	//		these paths must ALSO go through both the 'fft' and 'dac' nodes
	/*
	std::queue<Path*> pq;
	pq.push(new Path(nodes["svr"])); //this isnt correct
	__int64 count2 = 0;
	__int64 passes = 0;
	while(!pq.empty())
	{
		passes++;
		Path* curPath = pq.front();
		pq.pop();
		Node* curNode = curPath->getNode();
		if (curNode->getValue() == "fft") 
		{
			
		}
		else if (curNode->getValue() == "dac")
		{

		}

		//std::vector<std::string> *links = curNode->getLinks();

		for (std::string link : *curNode->getLinks()) {
			if (link == "out") { count2 += curPath->pass(); }
			else {
				pq.push(new Path(nodes[link]));
			}
		}
	}
	result2 = count2;
	*/
	std::cout << "Day 11: " << result1 << " " << result2 << std::endl;
}