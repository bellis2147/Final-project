#include <iostream>
#include <fstream>
#include <filesystem>
#include "minigit.hpp"

using namespace std;
namespace fs = std::filesystem;

const string filePath = "C:/Users/benfr/source/repos/bellis2147/Final-project/.vs/.minigit/";

 
miniGit::miniGit() {
//Delete and then reinitalize the repository (folder)
    fs::remove_all(".minigit"); // removes a directory and its contents
    cout << "Deleting .minigit directory..." << endl;
    fs::create_directory(".minigit");  // create a new directory
    cout << "Creating new .minigit directory..." << endl;
    
    
}

miniGit::~miniGit()
{
  fs::remove_all(".minigit");  

  doublyNode* dcurr = dhead;
  singlyNode* scurr = dhead->shead;
  while(dcurr!=NULL)
  {
      while(scurr!=NULL)
      {
          singlyNode* snext = scurr->next;
          scurr = nullptr;
          delete scurr;
          scurr = snext;
      }
      doublyNode* dnext = dcurr->next;
      dcurr = nullptr;
      delete dcurr;
      dcurr = dnext;
  }
  dhead->shead = nullptr;
  delete dhead->shead;
  dhead = nullptr;
  delete dhead;
}

void miniGit::initialize(){
    doublyNode* head = new doublyNode;
    head->commitNumber = 0;
    head->next = 0;
    head->previous = 0;
    dhead = head;

    singlyNode* shead = new singlyNode;
    shead->fileName = "";
    shead->fileVersion = 0;
    shead->next = NULL;
    dhead->shead = shead;

    
}


void miniGit::addFile(string fileName, int commitNum){
//Add a file to the current commit
    //FileName entered in main and passed into the function
    bool found = false;
    bool validFile = false;
    singlyNode * node = new singlyNode;

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


    //Check SLL to see if the file has already been added
    //Adding to the head if it is empty
    if (dhead->shead->fileName == "") {
        node->fileName = fileName;
        node->fileVersion = 0;
        node->next = NULL;
        dhead->shead = node;
        goto BEAM;
    }
        
        node = dhead->shead;
        while (found != true && node != NULL) {
            if (node->fileName == fileName) {
                found = true;
                
                break;
            }
            node = node->next;
        }
        if (found == true) {
            cout << "File already in commit, please enter a valid file" << endl;
            cin >> fileName;
        }
    
    
    //Add a new SLL node containing: Name of input file, name of repository file, pointer to the next node
    doublyNode * dnode = new doublyNode;
    dnode = dhead;
    int commit = dhead->commitNumber;
    for (int i = 0; i < dhead->commitNumber; i++) {
        dnode = dnode->next;
    }
    node = dhead->shead;
    while (node->next != NULL) {
        node = node->next;
    }

    //Creating the new SLL node
    singlyNode *s = new singlyNode;
    s->fileName = fileName;
    s->fileVersion = commitNum;
    s->next = NULL;
    node->next = s;
    
    
    //Naming of the file should be Name_00.txt 00 is the version number (from DLL)
   
    
    BEAM:
    //Outputing the SLL
    node = dhead->shead;
    cout << "====SLL====" << endl;
    while (node != NULL) {
        cout << node->fileName << "__" << node->fileVersion << "->";
        node = node->next;
    }
    cout << endl;
   
}

void miniGit::removeFile(string fileName, int commitNum) {

    //Check if system has been initialized
    if (dhead == NULL)
    {
        cout << "You must initialize first";
    }

    //Finds current commit
    else
    {
        doublyNode* dll = dhead;
        for (int i = 0; i < commitNum; i++)
        {
            dll = dll->next;
        }

        //Checks if files exist in current commit
        if (dll->shead == NULL)
        {
            cout << "No files in current commit" << endl;
        }
        else
        {
            //begin process of finding and deleting the file
            singlyNode* curr = dll->shead;
            singlyNode* prev = NULL;

            if (dll->shead->fileName == fileName)
            {
                dll->shead = curr->next;
                curr = nullptr;
                delete curr;
                cout << fileName << " has been successfully deleted from current commit" << endl;
            }
            else
            {

                while (curr != NULL)
                {

                    if (curr->fileName == fileName)
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
                        curr = curr->next;

                        //checks if the list has already been traversed
                        if (curr == NULL)
                        {
                            cout << "The file name given does not exist in the current commit." << endl;
                        }

                    }
                }


            }
            singlyNode* node;
            cout << "Current commit file list" << endl;
            node = dhead->shead;
            cout << "====SLL====" << endl;
            while (node != NULL) {
                cout << node->fileName << "__" << node->fileVersion <<  "->";
                node = node->next;
            }
            cout << "NULL" << endl;

        }




    }




    //Check the SLL to see if the file already exists, if so delete the SLL node

}

void miniGit::addCommit(int comNum){
//Traverse the entire SLL and for each node do the following
    //If the file is not already in the repository: copy the file to the repository, name should contain the fileVersion member
    //If the file is in the directory: Compare the file to the previous version, 
           //If the file is unchanged: Do nothing
           //If the file is changed: copy the file to the repository, name it with incremented version number, update SLL fileVersion to version
  
//After all files have been scanned
    //Create a new DLL node for the next version
    doublyNode* next = new doublyNode;
    doublyNode* prev = new doublyNode;
    doublyNode* n = new doublyNode;
    next = dhead;
    while (next != NULL) {
        prev = next;
        next = next->next;
    }
    n->previous = prev;
    n->next = NULL;
    //Copy the previous version of SLL to the new DLL node
    singlyNode* sNew = new singlyNode;
    singlyNode* sOld = new singlyNode;
    sOld = prev->shead;
    n->shead = sNew;
    while (sOld->next != NULL) {
        sNew = sOld;
        sOld = sOld->next;
        sNew = sNew->next;
    }
    //Change the commit number of DLL to that of previous node + 1
    n->commitNumber = prev->commitNumber + 1;
    next = n;
}

void miniGit::checkout(int commitNum){
    //Commit number entered in main function
    cout << "======Files For Commit #" << commitNum << "======" << endl;
    //Search the DLL and ouput files at that commit number
    doublyNode* d = new doublyNode;
    d = dhead;
    for (int i = 0; i < commitNum; i++) {
        if(d->next == NULL)
            d = d->next;
        else {
            cout << "Commit number does not exist" << endl;
            return;
        }
    }
    singlyNode* node = new singlyNode;
    node = dhead->shead;
    cout << "====SLL====" << endl;
    while (node != NULL) {
        cout << node->fileName << "__" << node->fileVersion << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}





