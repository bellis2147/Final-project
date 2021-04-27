#include <iostream>
#include <fstream>
#include <filesystem>
#include "final.hpp"
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

    while(open == true)
    {
        displayMenu();
        cin >> input;

        switch (input)
        {
            case 1:
            {

            }
            case 2:
            {

            }
            case 3:
            {

            }
            case 4:
            {

            }
            case 5:
            {

            }
            case 6:
            {
                
            }


        }


    }    
        

    
}