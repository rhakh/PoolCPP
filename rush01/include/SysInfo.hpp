#ifndef SYS_INFO_HPP
#define SYS_INFO_HPP

#include <string>
#include <cstdlib>
#include <unistd.h>
#include <limits.h>

std::string getHostname();
std::string getUsername();
std::string getDate();
std::string getTime();
std::string getCPUModel();
std::string getCPUClockSpeed();
std::string getCPUCoresNum();
std::string getCPUActivity();
std::string getRAM();
std::string getNetworkThroughput();
std::string execCommand(const char *cmd);

#endif // SYS_INFO_HPP