#include "Node.h"

class Path
{
private:
	Node* nextNode;
	bool fft = false;
	bool dac = false;
public:
	Path(Node* next);
	bool pass();
	Node* getNode();
};