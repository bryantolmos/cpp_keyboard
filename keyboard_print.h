#ifndef KEYBOARD_PRINT_H
#define KEYBOARD_PRINT_H

#include <iostream>
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
int keyboard_print(char c) {
    char top_row[] = "qwertyuiop";
    char middle_row[] = "asdfghjkl";
    char bottom_row[] = "zxcvbnm";

    build_up(c, top_row, " --- ");
    build_up(c, top_row, "| T |");
    build_up(c, top_row, " --- ");

    build_up(c, middle_row, " --- ");
    build_up(c, middle_row, "| M |");
    build_up(c, middle_row, " --- ");

    build_up(c, bottom_row, " --- ");
    build_up(c, bottom_row, "| B |");
    build_up(c, bottom_row, " --- ");

    return 0;
}

#endif