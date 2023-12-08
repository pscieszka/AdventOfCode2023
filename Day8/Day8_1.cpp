#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void calculateDay8() {

    vector<vector<string>> vec;
    ifstream file("input.txt");
    string line;
    string in = "LRRLRRLRLLLRLLRLRRLRRLRRLRRLLRLLRRRLRRRLRRLLLRLRRLLLLLRRRLRRRLRRRLRRLRRLRLRLRLRLRRRLRRRLRRRLRRLRRLRLRLRRLLRRRLLRRLRRLRRRLRLLRRLRRLRRRLRRRLRRRLRRRLRRLLLRRRLLRRLLLRRLRRLLRRLRRRLRRLRRLRRRLRRLLLRLRRRLLRRRLRLRRLRLRLRLRRRLRLRLRRLLRRLRRLRRLRRLLRLRLRRRLRRLRRLRRLRLRRRLRRLRLLRRLLRRLRLLLRLLRRRLRLRLLRRRR";
    string str;
    string str2;
    string str3;
    while (std::getline(file, line)) {
        str = line.substr(0,3);
        str2 = line.substr(7, 3);
        str3 = line.substr(12, 3);
        vector<string> temp = { str,str2,str3 };
        vec.push_back(temp);
    }
    int steps = 0;
    int idx=0;
    for (int j = 0; j < vec.size(); j++) {
        if (vec[j][0] == "AAA") {
            idx = j;
            break;
        }
    }
    

    string s;
    while (vec[idx][0] != "ZZZ") {
        for (int i = 0; i < in.size(); i++) {
            steps++;
            if (in[i] == 'L') {
                s = vec[idx][1];
            }
            else {
                s = vec[idx][2];
            }
            std::cout << "str:" << s << std::endl;
            std::cout << "steps:" << steps << std::endl;
            for (int j = 0; j < vec.size(); j++) {
                if (vec[j][0] == s) {
                    idx = j;
                    break;
                }
            }
        }
    }

    std::cout << "Steps:" << steps << std::endl;


}
