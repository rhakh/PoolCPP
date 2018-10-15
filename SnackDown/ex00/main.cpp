#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<int>    arr;

void    parseNK(std::string &line, int &n, int &k) {
    const char  *str = line.c_str();

    n = atoi(str);
    while (*str != ' ')
        str++;
    k = atoi(str);
}

int     algo(std::string &line, int n, int k) {
    std::stringstream   ss;
    int                 num = 0;
    int                 count = 0;

    ss << line;
    while (!ss.eof()) {
        ss >> num;
        arr.push_back(num);
    }

    std::sort(arr.begin(), arr.end(), std::greater<int>());
    for (int i = 0; i < arr.size() && arr[i] >= arr[k - 1]; i++)
        count++;

    arr.clear();
    return (count);
}

int main(void) {
    std::string line;
    int         t;
    int         n, k;
    int         res;

    std::getline(std::cin, line);
    t = std::stoi(line);
    for (; std::getline(std::cin, line);) {
        parseNK(line, n, k);
        std::getline(std::cin, line);
        res = algo(line, n, k);
        std::cout << res << std::endl;
    }

    return (0);
}