#include "Parser.h"

using namespace std; 

int main()
{
  // mainMenu(); //call the main menu function from Parser.h
  linkedList *p=new linkedList();
  readFileData(p);
  writeToFile(p->head);
  // printReverse(p->head);
  // p->printll();

  // linkedList *f=reverseList(p);
  // f->printll();
  
  // linkedList *f=  filterByLetters(p,'i');
  // f->printll();

  return 0;

}