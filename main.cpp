#include "Parser.h"

using namespace std;

int main()
{
  // mainMenu(); //call the main menu function from Parser.h
  linkedList *headNode = new linkedList();
  cout<<"MODULE 1"<<endl;
  readFileData(&headNode);

  cout<<"MODULE 2"<<endl;
  writeToFile(headNode);

  cout<<"MODULE 4"<<endl;
  linkedList *headNode4 = new linkedList();
  readFileData(&headNode);
  writeToFile(reverseList(headNode));

  cout<<"MODULE 5"<<endl;
  linkedList *headNode5 = new linkedList();
  readFileData(&headNode5);
  writeToFile(filterByLetters(headNode5,"f"));

  cout<<"MODULE 6"<<endl;
  linkedList *headNode6 = new linkedList();
  readFileData(&headNode6);
  writeToFile(rearrangeByEvenOddLength(headNode6));

  return 0;
}