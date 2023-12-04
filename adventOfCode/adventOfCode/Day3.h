#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int removeDots(string& str) {
    string res = "";
    for (auto& ch : str) {
        if (isdigit(ch)) {
            res += ch;
        }
    }
    return stoi(res);
}


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
            if (isdigit(lines[i][j])) {
                str = "";
                if (j + 2 < lines[i].size() && isdigit(lines[i][j + 2]) && isdigit(lines[i][j + 1])) {
                    str += lines[i][j];
                    lines[i][j] = '.';
                    str += lines[i][j + 1];
                    lines[i][j + 1] = '.';
                    str += lines[i][j + 2];
                    lines[i][j + 2] = '.';
                    bool condition =
                        (i - 1 >= 0 && (!isdigit(lines[i - 1][j]) && lines[i - 1][j] != '.')) ||
                        (i - 1 >= 0 && j + 1 < lines[i].size() && (!isdigit(lines[i - 1][j + 1]) && lines[i - 1][j + 1] != '.')) ||
                        (i - 1 >= 0 && j + 2 < lines[i].size() && (!isdigit(lines[i - 1][j + 2]) && lines[i - 1][j + 2] != '.')) ||
                        (i - 1 >= 0 && j + 3 < lines[i].size() && (!isdigit(lines[i - 1][j + 3]) && lines[i - 1][j + 3] != '.')) ||
                        (i - 1 >= 0 && j - 1 >= 0 && (!isdigit(lines[i - 1][j - 1]) && lines[i - 1][j - 1] != '.')) ||

                        (i + 1 < lines.size() && (!isdigit(lines[i + 1][j]) && lines[i + 1][j] != '.')) ||
                        (i + 1 < lines.size() && j + 1 < lines[i].size() && (!isdigit(lines[i + 1][j + 1]) && lines[i + 1][j + 1] != '.')) ||
                        (i + 1 < lines.size() && j + 2 < lines[i].size() && (!isdigit(lines[i + 1][j + 2]) && lines[i + 1][j + 2] != '.')) ||
                        (i + 1 < lines.size() && j + 3 < lines[i].size() && (!isdigit(lines[i + 1][j + 3]) && lines[i + 1][j + 3] != '.')) ||
                        (i + 1 < lines.size() && j - 1 >= 0 && (!isdigit(lines[i + 1][j - 1]) && lines[i + 1][j - 1] != '.')) ||

                        (j + 3 < lines[i].size() && (!isdigit(lines[i][j + 3]) && lines[i][j + 3] != '.')) ||
                        (j - 1 < lines[i].size() && (!isdigit(lines[i][j - 1]) && lines[i][j - 1] != '.'));

                    if (condition) {
                        cout << str << endl;
                        sum += stoi(str);
                    }

                }
                else if (j + 1 < lines[i].size() && !isdigit(lines[i][j + 1])) {
                    str += lines[i][j];
                    lines[i][j] = '.';
                    bool condition =
                        (i - 1 >= 0 && (!isdigit(lines[i - 1][j]) && lines[i - 1][j] != '.')) ||
                        (i - 1 >= 0 && j + 1 < lines[i].size() && (!isdigit(lines[i - 1][j + 1]) && lines[i - 1][j + 1] != '.')) ||
                        (i - 1 >= 0 && j - 1 >= 0 && (!isdigit(lines[i - 1][j - 1]) && lines[i - 1][j - 1] != '.')) ||

                        (i + 1 < lines.size() && (!isdigit(lines[i + 1][j]) && lines[i + 1][j] != '.')) ||
                        (i + 1 < lines.size() && j + 1 < lines[i].size() && (!isdigit(lines[i + 1][j + 1]) && lines[i + 1][j + 1] != '.')) ||
                        (i + 1 < lines.size() && j - 1 >= 0 && (!isdigit(lines[i + 1][j - 1]) && lines[i + 1][j - 1] != '.')) ||

                        (j + 1 < lines[i].size() && (!isdigit(lines[i][j + 1]) && lines[i][j + 1] != '.')) ||
                        (j - 1 < lines[i].size() && (!isdigit(lines[i][j - 1]) && lines[i][j - 1] != '.'));
                    if (condition) {
                        cout << str << endl;
                        sum += stoi(str);
                    }
                }
                else {
                    str += lines[i][j];
                    lines[i][j] = '.';
                    str += lines[i][j + 1];
                    lines[i][j + 1] = '.';
                    bool condition =
                        (i - 1 >= 0 && (!isdigit(lines[i - 1][j]) && lines[i - 1][j] != '.')) ||
                        (i - 1 >= 0 && j + 1 < lines[i].size() && (!isdigit(lines[i - 1][j + 1]) && lines[i - 1][j + 1] != '.')) ||
                        (i - 1 >= 0 && j + 2 < lines[i].size() && (!isdigit(lines[i - 1][j + 2]) && lines[i - 1][j + 2] != '.')) ||
                        (i - 1 >= 0 && j - 1 >= 0 && (!isdigit(lines[i - 1][j - 1]) && lines[i - 1][j - 1] != '.')) ||

                        (i + 1 < lines.size() && (!isdigit(lines[i + 1][j]) && lines[i + 1][j] != '.')) ||
                        (i + 1 < lines.size() && j + 1 < lines[i].size() && (!isdigit(lines[i + 1][j + 1]) && lines[i + 1][j + 1] != '.')) ||
                        (i + 1 < lines.size() && j + 2 < lines[i].size() && (!isdigit(lines[i + 1][j + 2]) && lines[i + 1][j + 2] != '.')) ||
                        (i + 1 < lines.size() && j - 1 >= 0 && (!isdigit(lines[i + 1][j - 1]) && lines[i + 1][j - 1] != '.')) ||

                        (j + 2 < lines[i].size() && (!isdigit(lines[i][j + 2]) && lines[i][j + 2] != '.')) ||
                        (j - 1 < lines[i].size() && (!isdigit(lines[i][j - 1]) && lines[i][j - 1] != '.'));
                    if (condition) {
                        cout << str << endl;
                        sum += stoi(str);

                    }
                }
            }
        }
    }
    cout << "sum=" << sum;
}