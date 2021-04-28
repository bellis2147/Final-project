#include <iostream>
#include <fstream>
#include <filesystem>
#include "minigit.hpp"
using namespace std;

void displayMenu()
{
    cout << "+==========Main Menu==========+" <, endl;
    cout << "1) initialize" << endl;
    cout << "2) add" << endl;
    cout << "3) rm" << endl;
    cout << "4) commit" << endl;
    cout << "5) checkout" << endl;
    cout << "6) quit" << endl;

}

int main(int argc, char* argv[])
{
    miniGit MG;
    
    int input;
    bool open = true;
    string fileName;
    int commitNum = 0;

    while(open == true)
    {
        displayMenu();
        cin >> input;

        switch (input)
        {
            case 1:
            { //Initalize
                MG.initialize();
                break;
            }
            case 2:
            { //Add a File
                cout << "Enter the name of a file to add" << endl;
                cin >> fileName;
                addFile(fileName, commitNum);
                break;
            }
            case 3:
            { //Remove a File
                cout << "Enter the name of a file to Remove" << endl;
                cin >> fileName;
                removeFile(fileName, commitNum);
                break;
            }
            case 4:
            { //Commit files
                MG.addCommit(commitNum);
                commitNum++;
                break;
            }
            case 5:
            { //Checkout
                //Traverse across the DLL to look at previous versions
                cout << "You will lose your local changes if they have not been commited" << endl;
                cout << "Enter the commit number you'd like to look at" << endl;
                cin >> commitNum;
                MG.checkout(commitNum);
                break;
            }
            case 6:
            { //Quit
                open = false;
                break;
            }
        }
    }    
return 0;
}

