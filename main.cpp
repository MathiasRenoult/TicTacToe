#include <iostream>

/*
 * comment !
 */
int main() {
    bool b[3][3] = {
            {true, true, true},
            {NULL, NULL, NULL},
            {NULL, NULL, NULL}
    };

    if(     ((b[0][0] == b[0][1]) && (b[0][1] == b[0][2]) && (b[0][2] != NULL) ||
             (b[0][0] == b[0][1]) && (b[0][1] == b[0][2]) && (b[0][2] != NULL) ||
             (b[0][0] == b[0][1]) && (b[0][1] == b[0][2]) && (b[0][2] != NULL) ||
             (b[0][0] == b[0][1]) && (b[0][1] == b[0][2]) && (b[0][2] != NULL) ||
             (b[0][0] == b[0][1]) && (b[0][1] == b[0][2]) && (b[0][2] != NULL) ||
             (b[0][0] == b[0][1]) && (b[0][1] == b[0][2]) && (b[0][2] != NULL) ||
             (b[0][0] == b[0][1]) && (b[0][1] == b[0][2]) && (b[0][2] != NULL) ||
             (b[0][0] == b[0][1]) && (b[0][1] == b[0][2]) && (b[0][2] != NULL)))
        std::cout << "Win!" << std::endl; else std::cout << "Not win!" << std::endl;

    return 0;
}
