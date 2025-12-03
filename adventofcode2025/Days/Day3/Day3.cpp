#include "./Day3.h"

void Day3::run() {

	std::string text;
	std::fstream file(input);

	while (getline(file, text)) {
		int sum = 0;
		std::string left = "0";
		std::string right = "0";
		for (int i = 0; i < text.size(); ++i) {
			if (right[0] > left[0]) {
				left = right;
				right = text[i];
				continue;
			}
			else if (text[i] > right[0]) {
				right = text[i];
			}
		}
		sum += stoi(left) * 10;
		sum += stoi(right);
		result1 += sum;
	};

	/*
		PART 2
	*/
	
	text = "";
	file.clear();
	file.seekg(0); //return to start of file

	while (getline(file, text)) {
		//get the first position of the biggest number that can still get 12 digits
		
		int tsize = text.size();
		int i1 = tsize - 12;
		int i2 = tsize - 11;
		int i3 = tsize - 10;
		int i4 = tsize - 9;
		int i5 = tsize - 8;
		int i6 = tsize - 7;
		int i7 = tsize - 6;
		int i8 = tsize - 5;
		int i9 = tsize - 4;
		int i10 = tsize - 3;
		int i11 = tsize - 2;
		int i12 = tsize - 1;
		std::string largest = "0";
		for (int i = 0; i < tsize - 11; ++i) {
			if (text[i] > largest[0]) {
				largest = text[i];
				i1 = i;
			}
		}
		largest = "0";
		for (int i = i1 + 1; i < tsize - 10; ++i) {
			if (text[i] > largest[0]) {
				largest = text[i];
				i2 = i;
			}
		}
		largest = "0";
		for (int i = i2 + 1; i < tsize - 9; ++i) {
			if (text[i] > largest[0]) {
				largest = text[i];
				i3 = i;
			}
		}
		largest = "0";
		for (int i = i3 + 1; i < tsize - 8; ++i) {
			if (text[i] > largest[0]) {
				largest = text[i];
				i4 = i;
			}
		}
		largest = "0";
		for (int i = i4 + 1; i < tsize - 7; ++i) {
			if (text[i] > largest[0]) {
				largest = text[i];
				i5 = i;
			}
		}
		largest = "0";
		for (int i = i5 + 1; i < tsize - 6; ++i) {
			if (text[i] > largest[0]) {
				largest = text[i];
				i6 = i;
			}
		}
		largest = "0";
		for (int i = i6 + 1; i < tsize - 5; ++i) {
			if (text[i] > largest[0]) {
				largest = text[i];
				i7 = i;
			}
		}
		largest = "0";
		for (int i = i7 + 1; i < tsize - 4; ++i) {
			if (text[i] > largest[0]) {
				largest = text[i];
				i8 = i;
			}
		}
		largest = "0";
		for (int i = i8 + 1; i < tsize - 3; ++i) {
			if (text[i] > largest[0]) {
				largest = text[i];
				i9 = i;
			}
		}
		largest = "0";
		for (int i = i9 + 1; i < tsize - 2; ++i) {
			if (text[i] > largest[0]) {
				largest = text[i];
				i10 = i;
			}
		}
		largest = "0";
		for (int i = i10 + 1; i < tsize - 1; ++i) {
			if (text[i] > largest[0]) {
				largest = text[i];
				i11 = i;
			}
		}
		largest = "0";
		for (int i = i11 + 1; i < tsize; ++i) {
			if (text[i] > largest[0]) {
				largest = text[i];
				i12 = i;
			}
		}
		std::string sum = "";
		sum += text[i1];
		sum += text[i2];
		sum += text[i3];
		sum += text[i4];
		sum += text[i5];
		sum += text[i6];
		sum += text[i7];
		sum += text[i8];
		sum += text[i9];
		sum += text[i10];
		sum += text[i11];
		sum += text[i12];

		result2 += stoll(sum);
	}

	std::cout << "Day 3: " << result1 << " " << result2 << std::endl;
}