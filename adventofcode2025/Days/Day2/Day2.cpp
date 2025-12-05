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

		//result1 is all numbers between min and max that are the same front/back
		//e.g. 123123, 4545, 11, 5325253252
		result1 += calc(numbers, min, max);

		//result2 gets all numbers between min and max that has a repeating pattern
		//e.g. 11 222 3333 121212 424242424242 7234572345 432432432
		//result2 += calc2(numbers, min, max);
	}
	std::cout << "Day 2: " << result1 << " " << result2 << std::endl;
}
unsigned __int64 Day2::calc(std::unordered_set<unsigned __int64>& numbers, unsigned __int64 min, unsigned __int64 max) {
	unsigned __int64 SUM = 0;

	//get digits of the min
	int digitsmin = 0;
	unsigned __int64 temp = min;
	while (temp > 0) {
		digitsmin++;
		temp /= 10;
	}
	//get digits of the max
	int digitsmax = 0;
	temp = max;
	while (temp > 0) {
		digitsmax++;
		temp /= 10;
	}

	if (digitsmin % 2 == 1) 
	{ //digitsmin is ODD, add 1 and go next
		digitsmin++;
	}
	else {
		//create number based on first half of digitsmin.
		unsigned __int64 left = min / (unsigned __int64)pow(10, digitsmin / 2);
		unsigned __int64 cur = left + (left * pow(10, digitsmin / 2));
		unsigned __int64 nextdigits = pow(10, digitsmin);

		//number generated was LESS than the minimum.
		while (cur < min) { 
			//example: 100485 -> 100100
			//101101 will be over, just increasing left by 1 ONCE 'should' be enough.
			left++;
			cur = left + (left * pow(10, digitsmin / 2));
		}

		//generate numbers until we reach max or grow digits.
		while (cur <= max && cur < nextdigits) {
			SUM += cur;
			left++;
			cur = left + (left * pow(10, digitsmin / 2));
		}

		digitsmin += 2; //should we only increase by 2?
	}

	while (digitsmin <= digitsmax) {
		unsigned __int64 left = pow(10, (digitsmin / 2) - 1);
		unsigned __int64 cur = left + (left * pow(10, (digitsmin / 2)));
		unsigned __int64 nextdigits = pow(10, digitsmin);

		while (cur < max && cur < nextdigits) {
			SUM += cur;
			left++;
			cur = left + (left * pow(10, digitsmin / 2));
		}

		digitsmin += 2; //skip odd digits
	}

	return SUM;
}


unsigned __int64 Day2::calc2(std::unordered_set<unsigned __int64> &numbers, unsigned __int64 min, unsigned __int64 max) {
		unsigned __int64 sum = 0;
		unsigned __int64 left = 0;
		//get number of digits in min
		int digitsmin = 0;
		unsigned __int64 temp = min;
		while (temp > 0) {
			digitsmin++;
			temp /= 10;
		}
		int leftsize = 1;
		//get number of digits in max
		int digitsmax = 0;
		temp = max;
		while (temp > 0) {
			digitsmax++;
			temp /= 10;
		}
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