#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void calculateDay7() {

	vector<vector<string>> cards;
    ifstream file("input.txt");
    string line;
    string str;
    string str2;

    while (std::getline(file, line)) {
        str = line.substr(6);
        str2 = line.substr(0, 5);
        vector<string> temp = { str2,str };
        cards.push_back(temp);
    }
  
   

}
