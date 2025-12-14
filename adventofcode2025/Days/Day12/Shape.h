#include <string>
class Shape
{
private:
	int id;
	int size = 0;
public:
	Shape(int id, std::string l1, std::string l2, std::string l3);
	int getSize();
};