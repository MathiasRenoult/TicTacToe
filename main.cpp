#include <iostream>
#include <cstdlib>
/*
 * Efficient way to check if a player won a tic tac toe game.
 * The input is a 3x3 array of bool. NULL is the default state
 * and true/false are for the players.
 */
const int SIZE = 5;
/*
static int** FillArray(int** arr, int size)
{
    srand(time(0));
    for(int i = 0; i<size; i++)
    {
        for(int j = 0; j<size;j++)
        {
            arr[i][j] = (rand()%2) - 1;
        }
    }
    return arr;
}
*/

int main() {
    int b[SIZE][SIZE];
    srand(time(0));
    // generate random inputs
    for(int i = 0; i<SIZE; i++)
    {
        for(int j = 0; j<SIZE;j++)
        {
            b[i][j] = (rand()%3) - 1;
        }
    }
    /*
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
*/
    int r = 0,c = 0,d1 = 0, d2 = 0;
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            r += b[i][j];
            c += b[j][i];
            if(i == j)
            {
                d1 += b[i][j];
                d2 += b[j][i];
            }
        }
        if(r == SIZE || c == SIZE || d1 == SIZE || d2 == SIZE)
        {
            std::cout << "P1 win!" << std::endl;
            break;
        }
        else if (r == -SIZE || c == -SIZE || d1 == -SIZE || d2 == -SIZE)
        {
            std::cout << "P2 win!" << std::endl;
            break;
        }

        r = 0;
        c = 0;
        d1 = 0;
        d2 = 0;
    }

    // print array
    for(int i = 0; i<SIZE; i++)
    {
        for(int j = 0; j<SIZE;j++)
        {
            if(b[i][j] == -1) std::cout << "X";
            else if(b[i][j] == 1) std::cout << "O";
            else std::cout << "-";
        }
        std::cout << std::endl;
    }

    return 0;
}