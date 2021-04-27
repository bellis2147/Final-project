#include <iostream>
#include <fstream>
#include <filesystem>
#include "minigit.hpp"

using namespace std;
namespace fs = std::filesystem;

miniGit::minigit() {

}
miniGit::~minigit() {

}
void miniGit::initialize(){
//Delete and then reinitalize the repository (folder)
fs::remove_all(".minigit"); // removes a directory and its contents
fs::create_directory(".minigit");  // create a new directory

}

void miniGit::addFile(string fileName){
//Add a file to the current commit
    //FileName entered in main and passed into the function
    bool found = false;
    bool validFile = false;
    singlyNode node;
    string filePath = ".minigit/";
    //Check if file exists in current directory, if not keep prompting untill a valid file is entered
    while (validFile != true) {
        filePath.append(fileName);
        cout << "C://" << filePath << endl;
        if (fs::exists(filePath)) {
            validFile = true;
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
            if (node.fileName == fileName) {
                found = true;
                validFile = true;
                break;
            }
            node = node.next;
        }
        if (found == false) {
            cout << "File already in commit, please enter a valid file" << endl;
            cin >> fileName;
        }
    }

  
    //Add a new SLL node containing: Name of input file, name of repository file, pointer to the next node
    //Naming of the file should be Name_00.txt 00 is the version number (from DLL)
  
}

void miniGit::removeFile(string fileName){
//Remove a file from the current commit

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




