#pragma once
#include "Days.h"
#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

const unordered_map<std::string, int> numbers = { {"one", 1},{"two", 2},{"three", 3},{"four", 4},{"five", 5},{"six", 6},{"seven", 7},{"eight", 8},{"nine", 9} };
void calculateDay1()
{
	ifstream file("input.txt");
	string str;
	string line;
	int sum = 0;
	while (getline(file, line)) {
		str = line;
		char char1=0, char2=0;
		int id1, id2;
		int res1 = 0;
		int min1 = INT_MAX;
		for (const auto& number : numbers) {
			size_t found = line.find(number.first);
			while (found != string::npos) {
				if (found < min1) {
					min1 = found;
					res1 = number.second;
				}
				found = line.find(number.first, found + 1);
			}
		}
		
		int idx1 = INT_MAX;
		for (int i = 0; i<line.size(); i++) {
			if (line[i] >= 48 && line[i] <= 57) {
				char1 = line[i];
				idx1 = i;
				break;
			}
		} 
		if (idx1 < min1) {
			res1 = char1 - '0';
			min1 = idx1;
		}
		id1 = min1;

		int res2 = 0;
		size_t min2 = 0;
		for (const auto& number : numbers) {
			size_t found = line.find(number.first);
			while (found != string::npos) {
				if (found > min2) {
					min2 = found;
					res2 = number.second;
				}
				found = line.find(number.first, found + 1);
			}
			
		}
		int idx2 = 0;

		for (int i = line.size() - 1; i >= 0; i--) {
			if (line[i] >= 48 && line[i] <= 57) {
				char2 = line[i];
				idx2 = i;
				break;
			}
		}
		if (idx2 > min2) {
			res2 = char2 - '0';
			min2 =idx2;
		}
		id2 = min2;
		int num = 0;
		if (id1 == id2) {
			num = 10*res1 +res1;
		}
		else {
			num = 10 * res1 + res2;

		}
		sum += num;
		
	}
	cout << "sum = " << sum << endl;
	
}


