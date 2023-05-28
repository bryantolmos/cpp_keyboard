#include <iostream>

using namespace std;

#include "mac_linux.h"

int main() {
    /* checking what operating system user has */
    #ifdef _WIN32
        /* WINDOWS SPECIFIC CODE HERE
        cout << "running on windows" << endl; */
    #elif __linux__
        /* LINUX SPECIFIC CODE HERE
        cout << "running on linux" << endl; */
        real_time_input();
    #elif __APPLE__
        #include <TargetConditionals.h>
        #if TARGET_OS_MAC
            /* MAC-OS SPECIFIC CODE HERE
            cout << "running on macOS" << endl; */
            real_time_input();
        #endif
    #else 
        cout << "[ERROR 34404] : unknown operating system cant compile" << endl;
        return 34404;
    #endif

    return 0;

}