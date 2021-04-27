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
    singlyNode* head;
    doublyNode* next;
    doublyNode* previous;
}

class miniGit
{
    private:

    doublyNode* head;

    public:
      minigit();
      ~minigit();
      
      void initialize();
      void addFile(string fileName);
      void removeFile(string fileName);
      void addCommit(int comNum, doublyNode* prev);
      void checkout(int commitNum);



}
