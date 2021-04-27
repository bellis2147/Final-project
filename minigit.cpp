#include <iostream>
#include <fstream>
#include <filesystem>
#include "minigit.hpp"

using namespace std;


void initialize(){
//Delete and then reinitalize the repository (folder)
  
}

void addFile(string fileName){
//Add a file to the current commit
  //FileName entered in main and passed into the function
  
  //Check if file exists in current directory, if not keep prompting untill a valid file is entered
  
  //Check SLL to see if the file has already been added
  
  //Add a new SLL node containing: Name of input file, name of repository file, pointer to the next node
  //Naming of the file should be Name_00.txt 00 is the version number (from DLL)
  
}

void removeFile(string fileName){
//Remove a file from the current commit

//Check the SLL to see if the file already exists, if so delete the SLL node
  
}

void addCommit(int comNum, doublyNode* prev){
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

void checkout(int commitNum){
  //Commit number entered in main function
  cout << "======Files For Commit #" << commitNum << "======" << endl;
  //Search the DLL and ouput files at that commit number
}




