#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void calculateDay6() {

	vector<int>time = { 53,89,76,98 };
	vector<int>distance = { 313,1090,1214,1201 };

	
	int sum = 1;
	for(int j=0; j<4; j++){
		int cnt = 0;
		for (int i = 1; i < time[j]; i++) {
			if ((time[j] - i) * i> distance[j]) {
				cnt++;
			}
		}
		sum *= cnt;
		
	}
	cout << sum;
}
