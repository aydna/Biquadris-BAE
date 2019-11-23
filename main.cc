<<<<<<< HEAD
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
    
=======
#include <string>
#include <iostream>
#include "controller.h"
using namespace std;

int main(){
    Controller c;
    c.run(); // runs the controller (Ethan plz make it better <3)
>>>>>>> bca51f78903229d8f0ca5037d53e617ed26d9393
}