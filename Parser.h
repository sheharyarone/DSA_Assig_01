#include <fstream>
#include <iostream>
#include "Dictionary.h"
#include "List.h"
using namespace std;

string filename; // stores filename

void readFileData(linkedList *headNode) // reads text from a file and writes it to the AVL tree
{
  Dictionary *dict;
  string word, meaning;
  fstream fin;
  cout << "\e[46mEnter the filename\x1b[0m ";
  // cin.ignore();
  // cin>>filename;
  fin.open("words.txt");
  if (fin.is_open())
    cout << "\e[0;32mFile reading succesful.\x1b[0m\n";

  while (fin >> word) // write into file name
  {

    fin.ignore();
    getline(fin, meaning);
    dict = new Dictionary(word, meaning);
    // cout<<*dict<<endl;
    headNode->insertSorted(*dict);
  }
  fin.close();
}

void writeToFile(node *headNode) // write the linked list to a text file
{
  string word, meaning;

  fstream dictFile; // create fstream object for the file
  cout << "\e[46mEnter the filename\x1b[0m ";
  // cin.ignore();
  // cin >> filename;

  dictFile.open("writing_words.txt", std::ios::app); // create/open a text file in append mode. new information is always added to the end

  node *iterator = headNode;

  while (iterator != NULL)
  { // iterate over the linked list
    word = iterator->data.word;
    meaning = iterator->data.meaning;
    dictFile << word;
    dictFile << " " << meaning << endl; // write to data file
    iterator = iterator->next;          // advance to next node
  }
  dictFile.close();
  cout << "\e[0;32mDictionary entries added.\x1b[0m\n";
}
void printReverse(node *headNode)
{
  if (headNode != NULL)
  {
    printReverse(headNode->next);
    cout << headNode->data << endl;
  }
}

linkedList *reverseList(linkedList *headNode)
{
  // returns a linked list that is the reverse of the original list
  node *current, *next, *prev;

  prev = nullptr;
  headNode->tail = headNode->head;
  current = headNode->head;
  while (current != NULL)
  {
    next = current->next;

    current->next = prev;

    prev = current;
    current = next;
  }
  headNode->head = prev;

  return headNode;
}
bool is_matching(node *p, char letter)
{
  string word = p->data.word;
  for (int i = 0; i < word.length(); i++)
  {
    if (word[i] == letter)
    {
      return true;
    }
  }
  return false;
}

linkedList *filterByLetters(linkedList *headNode, char letter)
{
  // returns a linked list that contains only those words that have the
  node *loc, *ploc;
  ploc = headNode->head;
  node *temp;
  while (ploc != NULL)
  {
    if (is_matching(ploc, letter))
    {
      headNode->head = ploc;
      // cout<<headNode->head->data.word<<endl;
      loc = ploc->next;
      // cout<<loc->data.word<<endl;
      break;
    }
    else
    {
      temp = ploc;
      ploc = ploc->next;
      delete temp;
    }
  }
  while (loc != NULL)
  {
    if (is_matching(loc, letter))
    {
      ploc->next=loc;
      ploc=loc;
      loc=loc->next;
    }
    else
    {
      temp=loc;
      loc=loc->next;
      delete temp;
    }
  }
  ploc->next=NULL;
  headNode->tail=ploc;

  return headNode;
}
// void mainMenu() //menu function
// {
//   string word, meaning; //stores the word and meaning
//   char choice;  //stores user choice for the actions

//   cout << "\e[1;35mInput 's' to terminate the program anytime.\e[0;37m" << endl;
//   while (choice != 's') //while loop until 's' is entered
//   {
//     cout << "\n\x1b[36mPlease select an action: " << endl << endl;
//     cout << "\t1. Read file data" << endl;
//     cout << "\t2. Write to file" << endl;

//     cout << "\x1b[0m"; cin >> choice; cout << endl;
//     switch(choice)  //switch statement to check user input and calling respective functions
//     {
//       case('1'):
//       {
//         readFileData(list.start);
//       }; break;
//       case('2'):
//       {
//         writeToFile(list.start);
//       }; break;
//       case('s'):
//       {
//         cout << "\e[1;33mProgram terminated." << endl;
//       }; break;
//       default:
//         cout << "\x1b[31mInvalid action selected!\x1b[37m" << endl;
//     }
//   }
// }