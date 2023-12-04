#pragma once


#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;



void calculateDay4() {
    ifstream file("input.txt");
    string line;
    string str;
    int res = 0;
    set<int>st;
    vector<int> nums1, nums2;

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
        cout << "str1=" << str1 << endl;
        cout << "str2=" << str2 << endl;
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
        cout << "dupliates =" << duplicates << endl;
        int x = 0;
        for (int i = 0; i < duplicates; i++) {
            if(x==0 && duplicates>0) x = 1;
            x *= 2;
        }
        res += x;
        cout << "res=" << res/2<< endl;

        
    }







}
