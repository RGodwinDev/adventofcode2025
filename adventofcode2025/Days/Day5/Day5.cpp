#include "./Day5.h"

void Day5::run() {

	std::string text;
	std::fstream file(input);
	std::vector<std::pair<unsigned __int64, unsigned __int64>> ranges;
	while (getline(file, text) && text.size() > 0) {

		int dash = text.find('-');
		unsigned __int64 left = stoll(text.substr(0, dash));
		unsigned __int64 right = stoll(text.substr(dash+1));

		int l = 0;
		int r = ranges.size() - 1;
		bool inserted = false;

		while (l <= r) {
			if (inserted) { break; }
			int mid = l + ((r - l) / 2);
			if (ranges[mid].first <= left && ranges[mid].second >= left) {
				inserted = true;
				//left is within the range at mid
				if (ranges[mid].second >= right) {
					//right is also within the range at mid. 
					//this new range is completely overlapped by the range at mid.
					l = r + 1;
				}
				else {
					//right is greater, merge the ranges
					ranges[mid].second = right;
					while (mid < ranges.size() - 1 && ranges[mid].second >= ranges[mid + 1].first) {
						//keep merging ranges that we overlap.
						if (ranges[mid].second >= ranges[mid + 1].second) {
							//we completely over lap the range to the right, just remove it.
							ranges.erase(ranges.begin() + mid + 1);

						}
						else { //mid+1 is larger make its second ours then erase it
							ranges[mid].second = ranges[mid + 1].second;
							ranges.erase(ranges.begin() + mid + 1);

						}
					}
				}
			}
			else if (ranges[mid].first <= right && ranges[mid].second >= right) {
				//right is within the range at mid, but left is not.
				inserted = true;
				ranges[mid].first = left;
				while (mid > 0 && ranges[mid].first <= ranges[mid - 1].second) {
					if (ranges[mid].first <= ranges[mid - 1].first) { //mid overlaps mid-1
						ranges.erase(ranges.begin() + mid - 1);
					}
					else { //mid.first is within mid-1.first
						ranges[mid].first = ranges[mid - 1].first;
						ranges.erase(ranges.begin() + mid - 1);
					}
					mid--; //subtract 1 because we shifted it all left by 1.
				}
			}
			else if (ranges[mid].first > left && ranges[mid].second < right) {
				//mid is completely overlapped by this new range
				ranges[mid].first = left;
				ranges[mid].second = right;

				//merge ranges to the left
				while (mid > 0 && ranges[mid].first <= ranges[mid - 1].second) {
					if (ranges[mid].first <= ranges[mid - 1].first) { //mid overlaps mid-1
						ranges.erase(ranges.begin() + mid - 1);
					}
					else { //mid.first is within mid-1.first
						ranges[mid].first = ranges[mid - 1].first;
						ranges.erase(ranges.begin() + mid - 1);
					}
					mid--; //subtract 1 because we shifted it all left by 1.
				}

				//merge ranges to the right
				while (mid < ranges.size() - 1 && ranges[mid].second >= ranges[mid + 1].first) {
					//keep merging ranges that we overlap.
					if (ranges[mid].second >= ranges[mid + 1].second) {
						//we completely over lap the range to the right, just remove it.
						ranges.erase(ranges.begin() + mid + 1);

					}
					else { //mid+1 is larger make its second ours then erase it
						ranges[mid].second = ranges[mid + 1].second;
						ranges.erase(ranges.begin() + mid + 1);

					}
				}
			}
			else if (ranges[mid].first < left) {
				//move right
				l = mid + 1;
			}
			else {
				//move left
				r = mid - 1;
			}
		}


		if (!inserted) { //we didnt merge with another range.
			ranges.insert(ranges.begin() + l, { left, right });
		}

	};

	//merge ranges that are touching. 
	//123-456, 457-890 -> 123-890
	int i = 0;
	while (i < ranges.size()-1) {
		if (ranges[i].second == ranges[i + 1].first - 1) {
			ranges[i].second = ranges[i + 1].second;
			ranges.erase(ranges.begin() + i + 1);
		}
		else {
			i++;
		}
	}

	//Part 1:
	// For each food ID, check if it is within any fresh ID range.
	while (getline(file, text)) {

		unsigned __int64 value = stoll(text); //get the ID.

		int l = 0;
		int r = ranges.size() - 1;
		while (l <= r) {
			int mid = l + ((r - l) / 2);
			if (ranges[mid].first <= value && ranges[mid].second >= value) { 
				//within range!
				result1++;
				break;
			}
			else if (ranges[mid].first < value) {
				//move right
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
	};
	//ids done

	//part2, count how many fresh ids are possible.
	for (std::pair<unsigned __int64, unsigned __int64>& range : ranges) {
		result2 += (range.second - range.first) + 1;
	}
	
	std::cout << "Day 5: " << result1 << " " << result2 << std::endl;
}