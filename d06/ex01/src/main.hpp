#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>
#include <iostream>
#include <ctime>

#define STR_LENGTH  8

struct  serialized_t {
    char    str1[STR_LENGTH + 1];
    int     num;
    char    str2[STR_LENGTH + 1];
};

struct  Data {
    std::string str1;
    int         num;
    std::string str2;
};

#endif // MAIN_HPP