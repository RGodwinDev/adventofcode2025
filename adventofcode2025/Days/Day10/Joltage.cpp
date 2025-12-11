#include "Joltage.h"

Joltage::Joltage() {

}

Joltage::Joltage(std::string s) {
	int left = s.find('{');
	std::string jolt = s.substr(left + 1);
	while (left < s.size()) {
		this->jolts.push_back(stoi(jolt));
		left = s.find(',', left+1);
		if (left < 0) { break; }
		jolt = s.substr(left+1);
	}
}