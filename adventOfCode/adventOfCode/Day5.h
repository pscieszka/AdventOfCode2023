#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void calculateDay5() {

    //Parse data 
    ifstream file("input.txt");
    string line;
    string str;
    
    vector<int>seeds;
    vector<vector<int>>soil;
    vector<vector<int>>fert;

    while (std::getline(file, line)) {
         
        if (line.substr(0, 5) == "seeds") {
            str = line.substr(6);
            istringstream iss(str);
            int num;
            while (iss >> num) {
                seeds.push_back(num);
            }
        }
        else if(line.substr(0,12)=="seed-to-soil") {
            while (getline(file, line)) {
                if (line.substr(0, 18) == "soil-to-fertilizer") {
                    break;
                }
                str = line;
                istringstream iss(str);
                int num;
                vector<int>vec;
                while (iss >> num) {
                    vec.push_back(num);
                }
                soil.push_back(vec);
            }

 
        }
        else if (line.substr(0, 18) == "soil-to-fertilizer") {
            while (getline(file, line)) {
                if (line.substr(0, 19) == "fertilizer-to-water") {
                    break;
                }
                str = line;
                istringstream iss(str);
                int num;
                vector<int>vec;
                while (iss >> num) {
                    vec.push_back(num);
                }
                fert.push_back(vec);
            }
        }
        
    }

    
    
    file.close();
}
