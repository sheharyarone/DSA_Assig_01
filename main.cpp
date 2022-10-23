#include "Parser.h"

using namespace std; 

int main()
{
  // mainMenu(); //call the main menu function from Parser.h
  linkedList *p=new linkedList();

  // MPDULE 1
  readFileData(p);
  // cout<<"PRINTING NODES OF SINGLY LINKED LIST READ FROM FILE :"<<endl;
  // p->printll();
  // MODULE 2
  // writeToFile(p->head);

  // MODULE 3
  // cout<<"PRINTING THE LIST IN REVERSE ORDER:"<<endl;
  // printReverse(p->head);

  // MODULE 4
  // writeToFile(reverseList(p->head,p->tail));
  
  // MODULE 5
  // writeToFile(filterByLetters(p->head,'i'));

  // MODULE 6
  writeToFile(rearrangeByEvenOddLength(p->head));
  
  return 0;

}