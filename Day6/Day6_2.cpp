#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void calculateDay6() {

	vector<long long>time = { 53897698 };
	vector<long long>distance = { 313109012141201 };

	
	
		int cnt = 0;
		for (int i = 1; i < time[0]; i++) {
			if ((time[0] - i) * i> distance[0]) {
				cnt++;
			}
		}
		
		
	
	cout << cnt;
}
