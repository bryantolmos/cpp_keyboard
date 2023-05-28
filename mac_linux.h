#ifndef MAC_LINUX_H
#define MAC_LINUX_H

/* ask WHY i can user termios or unistd on mac but 
not on other systems */

#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

int real_time_input() {
    cout << "REAL TIME INPUT (press 0 to end program)" << endl;

    /* Set terminal to non-canonical mode */
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
                cout << "pressed key: " << c << endl;
            }
        }
    }
    
    /* restore terminal settings */
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);

    return 0;
}


#endif