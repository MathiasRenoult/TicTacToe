#include <iostream>

int main() {
    bool b[3][3] = {
            {true, true, true},
            {false, false, true},
            {false, true, false}
    };

    if(     (b[0][0] && b[0][1] && b[0][2])||
            (b[1][0] && b[1][1] && b[1][2])||
            (b[2][0] && b[2][1] && b[2][2])||
            (b[0][0] && b[1][0] && b[2][0])||
            (b[0][1] && b[1][1] && b[2][1])||
            (b[0][2] && b[1][2] && b[2][2])||
            (b[0][0] && b[1][1] && b[2][2])||
            (b[0][2] && b[1][1] && b[2][0])  )
        std::cout << "Win!" << std::endl; else std::cout << "Not win!" << std::endl;

    return 0;
}
