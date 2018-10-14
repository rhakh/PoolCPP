#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "SysInfo.hpp"

int main() {
    std::string line;

    line = getHostname();
    std::cout << line << std::endl;

    line = getUsername();
    std::cout << line << std::endl;

    line = getDate();
    std::cout << line << std::endl;

    line = getTime();
    std::cout << line << std::endl;

    line = getCPUModel();
    std::cout << line << std::endl;

    line = getCPUClockSpeed();
    std::cout << line << std::endl;

    line = getCPUCoresNum();
    std::cout << line << std::endl;

    line = getCPUActivity();
    std::cout << line << std::endl;

    line = getRAM();
    std::cout << line << std::endl;

    line = getNetworkThroughput();
    std::cout << line << std::endl;

	return 0;
}

// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <stdexcept>

// #include <cstdio>
// #include <cstdlib>


// class ExecCommand
// {
//     public:
//     std::string execCommand( const std::string &cmd )
//     {
//         std::string m_results;
//         FILE *pfd = popen( cmd.c_str(), "r" );

//         if ( pfd == 0 )
//         {
//             throw std::runtime_error( "Command or process could not be executed." );
//         }

//         while ( !feof(pfd) )
//         {
//             char buf[ 1024 ] = {0};

//             if ( fgets(buf, sizeof(buf), pfd) != NULL )
//             {
//                 m_results += std::string(buf);
//             }
//         }
//         pclose( pfd );

//         return (m_results);
//     }

//     std::string getResults() const
//     {
//         return m_results;
//     }

//     friend std::ostream & operator<<( std::ostream &os, const ExecCommand &exec )
//     {
//         os << exec.m_results;
//         return os;
//     }

//     private:
//     class Displayer
//     {
//         public:
//         Displayer( std::ostream &os ) : m_os(os) {}

//         void operator()( const std::string &str )
//         {
//             m_os << str;
//         }

//         private:
//         std::ostream &m_os;
//     };

//     std::string m_results;
// };


// void displayString( const std::string &str )
// {
//     std::cout << str;
// }


// int main( int argc, char **argv )
// {
//     try
//     {
//         std::string cmd;

//         for ( int i = 1; i < argc; ++i )
//         {
//         cmd += argv[i];
//         cmd += " ";
//         }

//         // execute the cmd and store results
//         //
//         ExecCommand exec( cmd );

//         // display the results
//         //
//         std::cout << exec << std::endl;

//         // alternate way to get the results
//         //
//         // const std::vector<std::string> &results = exec.getResults();
//         // std::for_each( results.begin(), results.end(), displayString );
//     }
//     catch ( std::exception &ex )
//     {
//         std::cerr << "Error: " << ex.what() << std::endl;
//     }

// return 0;
// }