#include <iostream>
#include <string> 
#include <sstream>
#include <fstream>
#include "controller.h"

using namespace std;


int main(int argc, char* argv[]) {
    //arg handling here
    bool textOnly = false;
    int seed = 0;
    string scriptfile1 = "sequence1.txt";
    string scriptfile2 = "sequence2.txt";
    int startLevel = 0;

    bool storeRun = false;
    string storeFile;

    string arg;
    for (int i = 1; i < argc; ++i){
        istringstream sock{argv[i]};
        sock >> arg;
        if (arg == "-text") textOnly = true;
        else if(arg == "-seed"){
            istringstream sock{argv[++i]};
            sock >> seed;
        }
        else if(arg == "-scriptfile1") scriptfile1 = argv[++i];
        else if(arg == "-scriptfile2") scriptfile2 = argv[++i];
        else if(arg == "-startlevel"){
            istringstream sock{argv[++i]};
            sock >> startLevel;
        }
        else if(arg == "-storerun"){ //stores the run
            istringstream sock{argv[++i]};
            sock >> arg;
            storeFile = arg;
            storeRun = true; 
        }
    }
    
    fstream fs;
    if (storeRun){
        fs.open("tests/" + storeFile + ".args", fstream::out);
        for (int i = 1; i < argc; ++i){
            istringstream sock{argv[i]};
            sock >> arg;
            if (arg != "-storerun"){
                fs << arg << " ";
            }
            else ++i;
        }
        fs.close();
        fs.open("tests/" + storeFile + ".in", fstream::out);
    }


    Controller controller{textOnly, seed, scriptfile1, scriptfile2, startLevel};
    string line;
    bool gamePersists = true;
    cout << controller << endl;

    while (gamePersists && getline(cin, line)) {
        gamePersists = controller.run(line);
        cout << controller << endl;
        if (storeRun) fs << line << endl ;
    }
    
}