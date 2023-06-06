#ifndef KEYBOARD_PRINT_H
#define KEYBOARD_PRINT_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const string NORMAL = "\033[90m";
const string HIGHLIGHT = "\033[37m";

int build_up(char input_character, const char* row, const char* output){
    for (int i = 0; i <= (strlen(row) - 1); i++) {
        if(input_character == row[i]) {
            cout << HIGHLIGHT << output << HIGHLIGHT;
        } else {
            cout << NORMAL << output << NORMAL;
        }
        if (i == (strlen(row) - 1)) {
            cout << endl;
        }
    }
    return 0;
}
int build_up_single(char input_character, const char* row) {
    for (int i = 0; i <= (strlen(row) - 1); i++) {
        string output_string = "| ";
        output_string += static_cast<char>(row[i]);
        output_string += " |";
        if (input_character == row[i]) {
            cout << HIGHLIGHT << output_string << HIGHLIGHT;
        } else {
            cout << NORMAL << output_string << NORMAL;
        }
        if (i == (strlen(row) - 1)) {
            cout << endl;
        }
    }
    return 0;
}
int keyboard_print(char c) {
    char top_row[] = "Tqwertyuiop[]\\";
    char middle_row[] = "Casdfghjkl;'E";
    char bottom_row[] = "Szxcvbnm,./S";

    build_up(c, top_row, " --- ");
    build_up_single(c, top_row);
    build_up(c, top_row, " --- ");

    cout << "   ";
    build_up(c, middle_row, " --- ");
    cout << "   ";
    build_up_single(c, middle_row);
    cout << "   ";
    build_up(c, middle_row, " --- ");

    cout << "       ";
    build_up(c, bottom_row, " --- ");
    cout << "       ";
    build_up_single(c, bottom_row);
    cout << "       ";
    build_up(c, bottom_row, " --- ");

    return 0;
}

#endif