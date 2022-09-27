#include <iostream>

/*
 * Efficient way to check if a player won a tic tac toe game.
 * The input is a 3x3 array of bool. NULL is the default state
 * and true/false are for the players.
 */
int main() {
    int b[3][3] = {
            {1, 0, 0},
            {0, -1, 0},
            {0, 0, -1}
    };

    if(     ((b[0][0] == b[0][1]) && (b[0][1] == b[0][2]) && (b[0][2] != 0) ||
             (b[1][0] == b[1][1]) && (b[1][1] == b[1][2]) && (b[1][2] != 0) ||
             (b[2][0] == b[2][1]) && (b[2][1] == b[2][2]) && (b[2][2] != 0) ||
             (b[0][0] == b[1][0]) && (b[1][0] == b[2][0]) && (b[2][0] != 0) ||
             (b[0][1] == b[1][1]) && (b[1][1] == b[2][1]) && (b[2][1] != 0) ||
             (b[0][2] == b[1][2]) && (b[1][2] == b[2][2]) && (b[2][2] != 0) ||
             (b[0][0] == b[1][1]) && (b[1][1] == b[2][2]) && (b[2][2] != 0) ||
             (b[0][2] == b[1][1]) && (b[1][1] == b[2][0]) && (b[2][0] != 0)))
    {
        std::cout << "Win!" << std::endl;
    }
    else
    {
        std::cout << "Not win!" << std::endl;
    }

    return 0;
}
