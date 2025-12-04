#include "./Day2.h"

void Day2::run() {
	std::string text;
	std::fstream file(input);
	getline(file, text); //theres only 1 line in the input.

	std::stringstream ss(text);
	std::string range; 

	//numbers we've already gotten. don't recount them.
	std::unordered_set<unsigned __int64> numbers = std::unordered_set<unsigned __int64>();

	while (std::getline(ss, range, ',')) {
		unsigned __int64 s = range.find('-');
		unsigned __int64 min = stoll(range.substr(0, (s)));
		unsigned __int64 max = stoll(range.substr(s + 1));
		//std::cout << std::endl << std::endl;
		//std::cout << "NEW RANGE " << range << std::endl;
		int digitsmin = 0;
		unsigned __int64 temp = min;
		while (temp > 0) { 
			digitsmin++;
			temp /= 10;
		}

		int digitsmax = 0;
		temp = max;
		while (temp > 0) {
			digitsmax++;
			temp /= 10;
		}
		//std::cout << "max/min digits: " << digitsmax << "/" << digitsmin << std::endl;

		unsigned __int64 half = calc(numbers, min, max, digitsmax / 2, digitsmin, digitsmax);
		result1 += half;
		result2 += half;

		for (int leftdigits = 1; leftdigits < digitsmax / 2; leftdigits++) {
			for (int i = digitsmin; i <= digitsmax; i++) {
				if (i % leftdigits == 0) {
					result2 += calc(numbers, min, max, leftdigits, digitsmin, digitsmax);
					break;
				}
			}
		}
		//std::cout << "Cur results! " << result1 << " " << result2 << std::endl;
	}
	std::cout << "Day 2: " << result1 << " " << result2 << std::endl;
}

//if we're calling this, assume leftsize is already mod0 on a number between min/max.
unsigned __int64 Day2::calc(std::unordered_set<unsigned __int64> &numbers, unsigned __int64 min, unsigned __int64 max, int leftsize, int digitsmin, int digitsmax) {
		unsigned __int64 sum = 0;
		unsigned __int64 left = 0;
		//std::cout << "left digits: " << leftsize << std::endl;
		//assume %leftsize == 0 with a number between min and max.
		
		//if digitsmin is odd, move over 1 more.
		//12345 would be 12, not 123.
		//leftsize 2 = 100, 12345 -> 123
		//leftsize 3 = 1000, 12345 -> 12
		//leftsize 5 = 100000, 1234567891 -> 12345
		
		//cases: 99 -> 111, 999 -> 1010 9999 -> 11111
		//even to odd, all 1s
		//odd to even, 10s

		left = min / (unsigned __int64)pow(10, digitsmin - (leftsize ));
		//std::cout << "left: " << left << std::endl;

		unsigned __int64 cur = 0;

		int tries = 0;
		int curdigits = 0;
		while (curdigits < digitsmin) {
			cur += left * (unsigned __int64)pow(10, leftsize * tries);
			tries++;
			unsigned __int64 temp = cur;
			curdigits = 0;
			while (temp > 0) {
				curdigits++;
				temp /= 10;
			}
			//std::cout << cur << std::endl;
		}
		while (cur < min) {
			left++;
			cur = 0;
			for (int i = -1; i < tries; ++i) {
				cur += left * (unsigned __int64)pow(10, leftsize * i);
			}
			//std::cout << cur << std::endl;
		}

		//std::cout << "starting cur: " << cur << std::endl;
		

		while (cur <= max) {
			if (!numbers.contains(cur)) {
				//std::cout << "adding: " << cur << std::endl;
				sum += cur;
				numbers.insert(cur);
			}
			else {
				//std::cout << "DUPLICATE:" << cur << std::endl;
			}
			left++;
			unsigned __int64 t = left;
			int digitcount = 0;
			while (t > 0) {
				digitcount++;
				t /= 10;
			}
			bool pass = true;

			if (digitcount != leftsize) {
				if (digitcount < digitsmax/2) {
					leftsize++;
				}
				else {
					break;
				}
				tries--;
				pass = false;
				for (int i = digitsmin; i <= digitsmax; ++i) {
					if (i % leftsize == 0) { pass = true; }
				}
				if (!pass) {
					//std::cout << "new left didnt pass: " << leftsize << std::endl;
					break;
				}
				left = 1 * (unsigned __int64)pow(10, leftsize-1);
				
				//std::cout << "new left " << left << std::endl;
				while (cur < min) {
					left++;
					cur = 0;
					for (int i = -1; i < tries; ++i) {
						cur += left * (unsigned __int64)pow(10, leftsize * i);
					}
					//std::cout << cur << std::endl;
				}
			}
			if (!pass) { continue; }

			//build up left again to add to cur
			cur = 0;
			for (int i = 0; i < tries; ++i) {
				cur += left * (unsigned __int64)pow(10, leftsize * i);
			}
			//std::cout << cur << std::endl;
		}
		//std::cout << "Leaving! " << cur << std::endl << std::endl;
		return sum;
}