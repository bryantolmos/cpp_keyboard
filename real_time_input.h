#ifndef REAL_TIME_INPUT_H
#define REAL_TIME_INPUT_H

#include <iostream>
using namespace std;

#ifdef _WIN32
    #include <conio.h>
#elif defined(__APPLE__) || defined(__linux__)
    #include <termios.h>
    #include <unistd.h>
#else 
    #error "Unknown operating system. Cannot compile :("
#endif

int real_time_input() {
    cout << "\nREAL TIME INPUT: PRESS 0 TO END PROGRAM" << endl;

    #ifdef _WIN32
        while (true) {
            if (_kbhit()) { /* check if a key is pressed */
                char c = _getch(); /* read the pressed key */
                if (c == '0') {
                    break;
                } else {
                    cout << c << endl;
                }
            }
        }
    #elif defined(__APPLE__) || defined (__linux__)
        /* set terminal to non-canonical mode */
        struct termios oldSettings, newSettings;
        tcgetattr(STDIN_FILENO, &oldSettings);
        newSettings = oldSettings;
        newSettings.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

        while (true) {
            char c;
            if (read(STDIN_FILENO, &c, 1) == 1) { /* reading a single character */
                if (c == '0') {
                    break;
                } else {
                    cout << c << endl;
                }
            }
        }
        /* restore terminal settings */
        tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
    #endif

    return 0;
}

#endif