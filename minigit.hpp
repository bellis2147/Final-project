#include <iostream>
using namespace std;


struct singlyNode
{
    string fileName;
    string fileVersion;
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
      void addFile(string fileName);
      void removeFile(string fileName);
      void addCommit(int comNum, doublyNode* prev);
      void checkout(int commitNum);



}
