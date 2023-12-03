#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int removeDots(string& str) {
    int res = 0;
    
    for (auto& ch : str) {
        if (isdigit(ch)) {
            
        }
    }
}
void calculateDay3() {
    std::ifstream file("input.txt");
    std::string line;
    int res = 0;
    vector<string> lines;
    while (std::getline(file, line)) {
        lines.push_back(line); //non necessary, but input file is not huge
    }
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            if (lines[i][j] != '.' && !isdigit(lines[i][j])) {
                
            }
        }
    }
}