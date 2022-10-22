#include "Parser.h"

using namespace std; 

int main()
{
  // mainMenu(); //call the main menu function from Parser.h
  linkedList *p=new linkedList();
  readFileData(p);
  // writeToFile(p->head);
  // printReverse(p->head);

  // linkedList *f=reverseList(p);
  // f->printll();
  
  return 0;

}