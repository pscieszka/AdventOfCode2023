#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

void calculateDay9() {
    std::ifstream file("input.txt");
    std::string line;
    int sum = 0;
    vector<int> vec;
    while (getline(file, line)) {
        vec.clear();
        istringstream iss(line);
        int num;
        int k = 1;
        while (iss >> num) {
            if (k >= 2) {
                vec.push_back(0);

            }
            vec.push_back(num);

            k++;
        }
       
        bool flag = true;
        int j = 1;
        while (flag) {
            flag = false;
            for (int i = j; i < vec.size() - (j - 1); i += 2) {

                vec[i] = vec[i + 1] - vec[i - 1];
                if (vec[i] != 0) {
                    flag = true;
                }
            }
            j++;
        }
        
        int res;
        
        for (int i = vec.size()-1; i >= 0; i--) {
            if (vec[i] == 0) {
                res = accumulate(vec.begin() + i, vec.end(), 0);
                break;
            }
        }
        sum += res;
         
    }
   
    cout << sum-1 << endl;
    
    file.close();
    

 
}