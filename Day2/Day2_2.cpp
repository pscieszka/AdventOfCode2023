#pragma once

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void calculateDay2() {
    std::ifstream file("input.txt");
    std::string line;
    int res = 0;
    
    while (std::getline(file, line)) {
        
        string colors[] = { "red", "green", "blue" };
        int minR = -1;
        int minG = -1;
        int minB = -1;
        for (const string& color : colors) {
            size_t found = line.find(color);
            while (found != string::npos) {
                int i = found - 1;
                string num = "";
                while (i >= 0 && (line[i] != ';' && line[i] != ':' && line[i] != ',')) {
                    if (line[i] >=48 && line[i] <= 57) {
                        num += line[i];
                    }
                    i--;
                }
               
                reverse(num.begin(), num.end());
                if (color == "red") {
                    if (stoi(num) > minR) {
                        minR = stoi(num);
                    }
                
                }
                else if (color == "green") {
                    if (stoi(num) > minG) {
                        minG = stoi(num);
                    }
                }
                else if (color == "blue") {
                    if (stoi(num) > minB) {
                        minB = stoi(num);
                    }
                }
                
                found = line.find(color, found + 1);
                
            }
           
        }
        res += (minB * minR * minG);
        

    }
    cout << "res=" << res << endl;
}
