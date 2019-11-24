#include <iostream>
#include "controller.h"

using namespace std;


int main(int argc, char* argv[]) {
    //arg handling here
    
    Controller controller{};
    string line;
    bool gamePersists = true;
    while (gamePersists && getline(cin, line)) {
        gamePersists = controller.run(line);
    }
    
}