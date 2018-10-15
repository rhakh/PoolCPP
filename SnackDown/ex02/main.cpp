#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<int>    arr;

int tellPeople(int currN) {
    int res = 0;
    for (int i = 0; i < currN; i++)
        res += arr[i];
    return (res);
}

int main(void) {
    int n;
    std::string line;

    // read T
    std::getline(std::cin, line);
    for (; std::getline(std::cin, line);) {
        int days = 0;
        int currN = 1;
        int num = 0;
        std::stringstream ss;
        
        n = atoi(line.c_str());

        std::getline(std::cin, line);
        ss << line;
        while (!ss.eof()) {
            ss >> num;
            arr.push_back(num);
        }
        
        while (currN < n) {
            days++;
            currN += tellPeople(currN);
        }

        arr.clear();
        std::cout << days << std::endl;
    }

    return (0);
}