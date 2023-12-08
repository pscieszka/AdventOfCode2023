#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

void calculateDay8() {
    std::ifstream file("input.txt");
    std::string line;

    std::vector<std::vector<std::string>> ws;
    while (std::getline(file, line)) {
        std::vector<std::string> tokens;
        size_t pos = 0;
        while ((pos = line.find(" ")) != std::string::npos) {
            tokens.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        tokens.push_back(line);
        ws.push_back(tokens);
    }

    std::vector<std::string> dirs = ws[0];
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> move;

    for (size_t i = 2; i < ws.size(); ++i) {
        const auto& start = ws[i][0];
        const auto& l = ws[i][1];
        const auto& r = ws[i][2];
        move["L"][start] = l;
        move["R"][start] = r;
    }

    auto length = [&](const std::string& here, bool part1) {
        for (size_t i = 0;; ++i) {
            const auto& d = dirs[i % dirs.size()];
            const auto& next = move[d][here];

            if ((part1 && next == "ZZZ") || (!part1 && next.back() == 'Z')) {
                return i + 1;
            }

            here = next;
        }
    };

    // Part 1
    std::cout << "Part 1: " << length("AAA", true) << std::endl;

    // Part 2
    std::vector<std::string> starts;
    for (size_t i = 2; i < ws.size(); ++i) {
        const auto& start = ws[i][0];
        if (start.back() == 'A') {
            starts.push_back(start);
        }
    }

    auto lcm = [](int a, int b) { return std::lcm(a, b); };
    int result = std::accumulate(starts.begin(), starts.end(), 1, [&](int acc, const std::string& s) {
        return lcm(acc, length(s, false));
        });

    std::cout << "Part 2: " << result << std::endl;
}