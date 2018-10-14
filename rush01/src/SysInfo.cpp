#include "SysInfo.hpp"

std::string execCommand(const char *cmd) {
    std::string m_results;
    FILE *pfd = popen(cmd, "r");

    if (pfd == 0) {
        throw std::runtime_error("Command or process could not be executed.");
    }

    while (!feof(pfd)) {
        char buf[1024] = {0};

        if ( fgets(buf, sizeof(buf), pfd) != NULL )
            m_results += std::string(buf);
    }
    pclose( pfd );

    return (m_results);
}

std::string getHostname() {
    char hostname[_SC_HOST_NAME_MAX];

    gethostname(hostname, _SC_HOST_NAME_MAX);

    return (std::string(hostname));
}

std::string getUsername() {
    return (getenv("USER"));
}

std::string getDate() {
    std::string res;

    res = execCommand("top | head -n 10 | sed -n '2p' | cut -d' ' -f 1");
    res.erase(std::remove(res.begin(), res.end(), '\n'), res.end());
    return (res);
}

std::string getTime() {
    std::string res;

    res = execCommand("top | head -n 10 | sed -n '2p' | cut -d' ' -f 2");
    res.erase(std::remove(res.begin(), res.end(), '\n'), res.end());
    return (res);
}

std::string getCPUModel() {
    std::string res;

    res = execCommand("sysctl -n machdep.cpu.brand_string");
    res.erase(std::remove(res.begin(), res.end(), '\n'), res.end());
    return (res);
}

std::string getCPUClockSpeed() {
    std::string res;

    res = execCommand("sysctl -n hw.cpufrequency");
    res.erase(std::remove(res.begin(), res.end(), '\n'), res.end());
    return (res);
}

std::string getCPUCoresNum() {
    std::string res;

    res = execCommand("sysctl -n hw.ncpu");
    res.erase(std::remove(res.begin(), res.end(), '\n'), res.end());
    return (res);
}

std::string getCPUActivity() {
    std::string res;

    res = execCommand("top | head -n 10 | grep 'CPU usage' | cut -d' ' -f2-");
    res.erase(std::remove(res.begin(), res.end(), '\n'), res.end());
    return (res);
}

std::string getRAM() {
    std::string res;

    res = execCommand("top | head -n 10 | grep 'PhysMem' | cut -d ' ' -f 2-");
    res.erase(std::remove(res.begin(), res.end(), '\n'), res.end());
    return (res);
}

std::string getNetworkThroughput() {
    std::string res;

    res = execCommand("top | head -n 10 | grep 'Networks' | cut -d ' ' -f 2-");
    res.erase(std::remove(res.begin(), res.end(), '\n'), res.end());
    return (res);
}
