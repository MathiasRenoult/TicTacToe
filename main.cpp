#include <iostream>
#include <ctime>
#include <vector>

/*
 * Efficient way to check if a player won a tic tac toe game.
 * The input is a 3x3 array of bool. NULL is the default state
 * and true/false are for the players.
 */
const int SIZE = 3;

void PrintArray(int array[][SIZE])
{
    for(int i = 0; i<SIZE; i++)
    {
        for(int j = 0; j<SIZE;j++)
        {
            if(array[i][j] == -1) std::cout << "X";
            else if(array[i][j] == 1) std::cout << "O";
            else std::cout << "-";
        }
        std::cout << std::endl;
    }
}

void GenerateArray(int array[][SIZE])
{
    srand(time(0));
    for(int i = 0; i<SIZE; i++)
    {
        for(int j = 0; j<SIZE;j++)
        {
            array[i][j] = (rand()%3) - 1;
        }
    }
}

int main() {
    int b[SIZE][SIZE] =
            {
                    {0,0,-1},
                    {0,-1,0},
                    {-1,0,0},
            };

    //GenerateArray(b);

    int row = 0,column = 0,diagonal1 = 0, diagonal2 = 0;
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            row += b[i][j];
            column += b[j][i];
            if(i == j)
            {
                diagonal1 += b[i][j];
            }
            if(i == SIZE-j-1)
            {
                diagonal2 += b[i][j];
            }
        }
        if(row == SIZE || column == SIZE || diagonal1 == SIZE || diagonal2 == SIZE)
        {
            std::cout << "P1 win!" << std::endl;
            break;
        }
        else if (row == -SIZE || column == -SIZE || diagonal1 == -SIZE || diagonal2 == -SIZE)
        {
            std::cout << "P2 win!" << std::endl;
            break;
        }

        row = 0;
        column = 0;
    }

    PrintArray(b);

    return 0;
}