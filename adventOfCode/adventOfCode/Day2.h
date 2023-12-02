#pragma once

#include <fstream>
#include <string>
#include <iostream>
using namespace std;


void parser() {

}
void calculateDay2() {
    std::ifstream file("input.txt");
    std::string line;
    int gamecnt = 1;
    int res = 0;
    
    while (std::getline(file, line)) {
        
        int gameId = gamecnt;

        string colors[] = { "red", "green", "blue" };

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
                    if (stoi(num) > 12) {
                        gameId = 0;
                    }
                }
                else if (color == "green") {
                    if (stoi(num) > 13) {
                
                        gameId = 0;
                    }
                }
                else if (color == "blue") {
                    if (stoi(num) > 14) {
                        gameId = 0;
                    }
                }
                
                found = line.find(color, found + 1);
                
            }
           
        }
        res += gameId;
        

        gamecnt++;
    }
    cout << "res=" << res << endl;
}
