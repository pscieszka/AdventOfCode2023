#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void calculateDay4() {

    //Parse data 
    ifstream file("input.txt");
    string line;
    string str;
    vector<vector<int>>dp;
    while (std::getline(file, line)) {
        str = line;
        int idx1 = 0;
        int idx2 = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ':') {
                idx1 = i + 1;
                break;
            }
        }
        for (int i = idx1; i < line.size(); i++) {
            if (line[i] == '|') {
                idx2 = i + 1;
                break;
            }
        }
        string str1 = line.substr(idx1, idx2 - idx1 - 1);
        string str2 = line.substr(idx2);
       
        istringstream iss1(str1);
        istringstream iss2(str2);

        unordered_map<int, int> occurrences;

        int number;
        while (iss1 >> number) {
            occurrences[number]++;
        }

        while (iss2 >> number) {
            occurrences[number]++;
        }

        int duplicates = 0;
        for (const auto& entry : occurrences) {
            if (entry.second > 1) {
                duplicates += entry.second - 1;
            }
        }
        vector<int> row;
        row.push_back(1);
        row.push_back(duplicates);
        dp.push_back(row);

    }
    //logic of task
    for (int i = 0; i < dp.size(); ++i) {
        int cards = dp[i][0];
        for (int j = 0; j < cards; j++) {
            for (int k = i+1; k < dp[i][1]+i+1; k++) {
                dp[k][0]++;
            }
        }
    }
    int sum = 0;
    for (size_t i = 0; i < dp.size(); ++i) {
        sum += dp[i][0];
    }
    cout << "sum=" << sum;





}
