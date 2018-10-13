#include <iostream>
#include <string>
#include <vector>

void    parseNK(std::string &line, int &n, int &k) {
    const char  *str = line.c_str();

    n = atoi(str);
    while (*str != ' ')
        str++;
    k = atoi(str);
}

int     algo(std::string &line) {

    return (0);
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
        res = algo(line);

        std::cout << "N: " << n << " K: " << k << std::endl;
    }

    return (0);
}