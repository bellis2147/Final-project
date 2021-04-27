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
    miniGit* MG;
    
    int input;
    bool open = true;
    string fileName;
    int commitNum;

    while(open == true)
    {
        displayMenu();
        cin >> input;

        switch (input)
        {
            case 1:
            { //Initalize

            }
            case 2:
            { //Add a File

                cout << "Enter the name of a file to add" << endl;
                cin >> fileName;
                addFile(fileName);
            }
            case 3:
            { //Remove a File
                cout << "Enter the name of a file to Remove" << endl;
                cin >> fileName;
                removeFile(fileName);
            }
            case 4:
            { //Commit files

            }
            case 5:
            { //Checkout
              //Traverse across the DLL to look at previous versions
              cout << "You will loose your local changes if they have not been commited" << endl;
              cout << "Enter the commit number you'd like to look at" << endl;
              cin >> commitNum;
              checkout(commitNum);
            }
            case 6:
            { //Quit
                open = false;
            }


        }


    }    
        

    
}
