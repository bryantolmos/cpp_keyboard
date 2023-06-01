#include <iostream>
/* library to clear terminal */
#include <cstdlib>

#include "keyboard_print.h"

using namespace std;

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h> /* included this to be part of the windows terminal clear */
    void windows_clear() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coordScreen = {0, 0};
        DWORD cCharsWritten;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD dwConSize;

        GetConsoleScreenBufferInfo(hConsole, &csbi);
        dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

        FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
        SetConsoleCursorPosition(hConsole, coordScreen);
    }
#elif defined(__APPLE__) || defined(__linux__)
    #include <termios.h>
    #include <unistd.h>
    void mac_clear() {
        cout << "\033[2J\033[1;1H";
    }
#else 
    #error "Unknown operating system. Cannot compile :("
#endif

int main() {
    cout << "\nREAL TIME INPUT: PRESS 0 TO END PROGRAM" << endl;

    #ifdef _WIN32
        while (true) {
            if (_kbhit()) { /* check if a key is pressed */
                char c = _getch(); /* read the pressed key */
                if (c == '0') {
                    break;
                } else {
                    windows_clear();
                    keyboard_print();
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
                    mac_clear();
                    keyboard_print(c);
                }
            }
        }
        /* restore terminal settings */
        tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
    #endif

    return 0;
}