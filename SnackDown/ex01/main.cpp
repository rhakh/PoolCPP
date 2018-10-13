#include <iostream>
#include <string>
#include <vector>

std::vector<int> arr = {6, 10, 14, 15, 21, 22, 26, 33, 34, 35,
                        38, 39, 46, 51, 55, 57, 58, 62, 65, 69,
                        74, 77, 82, 85, 86, 87, 91, 93, 94, 95,
                        106, 111, 115, 118, 119, 122, 123, 129,
                        133, 134, 141, 142, 143, 145, 146, 155,
                        158, 159, 161, 166, 177, 178, 183, 185, 187};

bool    isSemiSummed(int n) {
    for (unsigned i = 0; i < arr.size(); i++) {
        for (unsigned j = 0; j < arr.size(); j++) {
            if (arr[i] + arr[j] == n)
                return (true);
        }
    }
    return (false);
}

int main(void) {
    std::string line;
    int         t;
    int         n;

    std::getline(std::cin, line);
    t = std::stoi(line);
    for (; std::getline(std::cin, line);) {
        n = std::stoi(line);
        if (isSemiSummed(n))
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }

    return (0);
}