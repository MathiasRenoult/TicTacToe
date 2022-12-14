#include <iostream>
#include <ctime>
#include <vector>

/*
 * Efficient way to check if a player won a tic tac toe game.
 * The input is a 3x3 array of bool. NULL is the default state
 * and true/false are for the players.
 */
const int PLAYMODE = 0;
const int SIZE = 3;
int8_t board[SIZE][SIZE] =
        {
                {0,0,-1},
                {0,-1,0},
                {-1,0,0},
        };
/*
 * Affiche le tableau de jeu dans la console
 */
void PrintArray()
{
    std::cout << "---------------" << std::endl;
    for(auto & i : board)
    {
        std::cout << "|";
        for(signed char j : i)
        {
            if(j == -1) std::cout << " X ";
            else if(j == 1) std::cout << " O ";
            else std::cout << "   ";
            std::cout << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "---------------" << std::endl;
}

/*
 * Remplis le tabelau de jeu avec des valeurs aléatoires de -1, 0 ou 1
 */
void GenerateRandomArray()
{
    srand(time(0));
    for(auto & i : board)
    {
        for(signed char & j : i)
        {
            j = (rand()%3) - 1;
        }
    }
}

/*
 * Initialise le tableau en remplissant toutes ses cases avec un 0
 */
void InitializeArray()
{
    for(auto & i : board)
    {
        for(signed char & j : i)
        {
            j = 0;
        }
    }
}

/*
 * Gère le tour de jeu pour un joueur humain
 */
void HumanPlay(bool isCrossPlaying)
{
    std::string cell;
    uint8_t xCoord, yCoord;
    bool stayInLoop = true;

    isCrossPlaying ? std::cout << "Cross is playing" << std::endl : std::cout << "Circle is playing" << std::endl;

    do {
        std::cin >> cell;
        xCoord = cell[0] - '0';
        yCoord = cell[1] - '0';
        if(cell.length() == 2)
        {
            if(xCoord <= SIZE && xCoord > 0 && yCoord <= SIZE && yCoord > 0)
            {
                //std::cout << "Played on cell " + std::to_string((xCoord*10) + yCoord) << std::endl;
                if(board[xCoord][yCoord] == 0)
                {
                    board[xCoord][yCoord] = isCrossPlaying ? -1 : 1;
                    stayInLoop = false;
                }
                else
                {
                    std::cout << "You can't play on a non-empty cell. Please play again." << std::endl;
                }
            }
            else
            {
                std::cout << "cell[0] = " + std::to_string(cell[0]) + " and cell[1] = " + std::to_string(cell[1]) << std::endl;
                std::cout << "You can't enter coordinates below 0 or above the size of the playing board (" + std::to_string(SIZE) + ")." << std::endl;
            }
        }
        else
        {
            std::cout << "Please enter only to numbers (x and y coordinate) ranging from 1 to " + std::to_string(SIZE) + "." << std::endl;
        }
    } while (stayInLoop);
}

/*
 * Gère un tour de jeu pour une IA
 */
void AIPlay(bool isCrossPlaying)
{

}

/*
 * Parcours le tableau et détermine s'il y a un gagnant.
 */
uint8_t CheckForWinner()
{
    bool equality = true;
    int8_t row = 0,column = 0,diagonal1 = 0, diagonal2 = 0;

    for(auto & i : board)
    {
        for(uint8_t j=0;j<SIZE;j++)
        {
            if(i[j] == 0) equality = false;
        }
    }

    if(!equality)
    {
        for(uint8_t i=0;i<SIZE;i++)
        {
            for(uint8_t j=0;j<SIZE;j++)
            {
                row += board[i][j];
                column += board[j][i];
                if(i == j)
                {
                    diagonal1 += board[i][j];
                }
                if(i == SIZE-j-1)
                {
                    diagonal2 += board[i][j];
                }
            }
            if(row == SIZE || column == SIZE || diagonal1 == SIZE || diagonal2 == SIZE)
            {
                return 1;
            }
            else if (row == -SIZE || column == -SIZE || diagonal1 == -SIZE || diagonal2 == -SIZE)
            {
                return 2;
            }

            row = 0;
            column = 0;
        }
    }
    else
    {
        std::cout << "Nobody won..." << std::endl;
        return 2;
    }

    return 0;
}

/*
 * Gère le jeu complet
 */
void GameLoop()
{
    bool inGame = true;
    bool isCrossPlaying = rand()%2;
    bool playMode;

    std::string playerChoice;
    std::cout << "Choose play mode (1 = 2-player, 2 = player VS Human)" << std::endl;
    std::cin >> playerChoice;
    playerChoice == "1" ? playMode = false : playMode = true;

    isCrossPlaying ? std::cout << "Cross starts to play as P1" << std::endl : std::cout << "Circle starts to play as P1" << std::endl;
    InitializeArray();
    while(inGame)
    {
        playMode == 0 ? HumanPlay(isCrossPlaying) : AIPlay(isCrossPlaying);
        isCrossPlaying = !isCrossPlaying;
        PrintArray();
        if(CheckForWinner() != 0)
        {
            if(CheckForWinner() != 2)
            {
                CheckForWinner() == 1 ? std::cout << "P1 win!" << std::endl : std::cout << "P2 win!" << std::endl;
            }

            inGame = false;
        }
    }
}


int main() {
    while (1)
    {
        GameLoop();
    }

    return 0;
}