#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;



void calculateDay3() {
    std::ifstream file("input.txt");
    std::string line;
    int res = 0;
    vector<string> lines;
    while (std::getline(file, line)) {
        lines.push_back(line); //input file is not huge
    }
    string str = "";
    int sum = 0;

    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            
        }
    }




}
