#include <iostream>
using namespace std;


struct singlyNode
{
    string fileName;
    int fileVersion;
    singlyNode* next;
}

struct doublyNode
{
    int commitNumber;
    singlyNode* shead;
    doublyNode* next;
    doublyNode* previous;
}

class miniGit
{
    private:


    doublyNode* dhead;

    public:
      minigit();
      ~minigit();
      
      void initialize();
      void addFile(string fileName, int commitNum);
      void removeFile(string fileName, int commitNum);
      void addCommit(int comNum);
      void checkout(int commitNum);



}
