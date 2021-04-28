#include <iostream>
#include <fstream>
#include <filesystem>
#include "minigit.hpp"

using namespace std;
namespace fs = std::filesystem;

miniGit::miniGit(){
    fs::remove_all(".minigit"); // removes a directory and its contents
    cout << "Deleting .minigit directory..." << endl;
    fs::create_directory(".minigit");  // create a new directory
    cout << "Creating new .minigit directory..." << endl;
    //Create the head of DLL
    doublyNode* head = new doublyNode;
    head->commitNumber = 0;
    head->next = 0;
    head->previous = 0;
    dhead = head;

}
    
void initialize(){
//Delete and then reinitalize the repository (folder)
    
}

void miniGit::addFile(string fileName){
//Add a file to the current commit
    //FileName entered in main and passed into the function
    bool found = false;
    bool validFile = false;
    singlyNode * node = new singlyNode;
    string filePath = "C:/Users/benfr/source/repos/bellis2147/Final-project/.vs/.minigit/";
    //Check if file exists in current directory, if not keep prompting untill a valid file is entered
    while (validFile != true) {
        
        cout << filePath + fileName << endl;
        if (fs::exists(filePath + fileName)) {
            validFile = true;
            cout << "File exists..." << endl;
        }
        else {
            cout << "File does not exist in directory, enter a different file" << endl;
            cin >> fileName;
        }
    }

    validFile = false;
    //Check SLL to see if the file has already been added
    
    while (validFile != true) {

        node = dhead->shead;
        while (found != true) {
            if (node->fileName == fileName) {
                found = true;
                validFile = true;
                break;
            }
            node = node->next;
        }
        if (found == false) {
            cout << "File already in commit, please enter a valid file" << endl;
            cin >> fileName;
        }
    }

    
    //Add a new SLL node containing: Name of input file, name of repository file, pointer to the next node
    doublyNode * dnode = new doublyNode;
    int commit = dhead->commitNumber;
    for (int i = 0; i < dhead->commitNumber; i++) {
        dnode = dnode->next;
    }
    node = dhead->shead;
    while (node != NULL) {
        node = node->next;
    }
    //Creating the new SLL node
    node->fileName = fileName + "00";
    node->fileVersion = commit;
    //Naming of the file should be Name_00.txt 00 is the version number (from DLL)
  
}



void miniGit::removeFile(string fileName, int commitNum){

    //Check if system has been initialized
    if(dhead == NULL)
    {
        cout << "You must initialize first";
    }
    
    //Finds current commit
    else
    {
        doublyNode * dll = dhead;
        for(int i = 0; i < commitNum; i++)
        {
            dll = dll->next;
        }

        //Checks if files exist in current commit
        if(dll->shead == NULL)
        {
            cout << "No files in current commit" << endl;
        }
        else
        {
            //begin process of finding and deleting the file
            singlyNode* curr = dll->shead;
            singlyNode* prev = NULL;

            if(dll->shead->fileName == fileName)
            {
                curr->next == dll->shead;
                curr= nullptr
                delete curr;
                cout << fileName << " has been successfully deleted from current commit" << endl;
            }
            else
            {
                while(curr!=NULL)
                {

                    if(curr->fileName == fileName)
                    {
                        //deletes file and keeps LL integrity
                        prev->next = curr->next;
                        curr = nullptr;
                        delete curr;
                        cout << fileName << " has been successfully deleted from current commit" << endl;
                        break;
                    }
                    else
                    {
                        //Moves to next file in list
                        prev = curr;
                        curr= curr->next;
                        
                        //checks if the list has already been traversed
                        if(curr==NULL)
                        {
                            cout << "The file name given does not exist in the current commit." << endl;
                        }

                    }
                }


            }
            singlyNode* print = dll->shead;
            cout << "Current commit file list" << endl;
            while(print!=NULL)
            {
                cout << print->fileName >> "->" << endl;
                print = print->next;
            }

        }




    }




//Check the SLL to see if the file already exists, if so delete the SLL node
  
}

void miniGit::addCommit(int comNum, doublyNode* prev){
//Traverse the entire SLL and for each node do the following
    //If the file is not already in the repository: copy the file to the repository, name should contain the fileVersion member
    //If the file is in the directory: Compare the file to the previous version, 
           //If the file is unchanged: Do nothing
           //If the file is changed: copy the file to the repository, name it with incremented version number, update SLL fileVersion to version
  
//After all files have been scanned
  //Create a new DLL node for the next version
  //Copy the previous version of SLL to the new DLL node
  //Change the commit number of DLL to that of previous node + 1
  
  
}

void miniGit::checkout(int commitNum){
  //Commit number entered in main function
  cout << "======Files For Commit #" << commitNum << "======" << endl;
  //Search the DLL and ouput files at that commit number
}




