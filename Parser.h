#include <fstream>
#include <iostream>
#include "Dictionary.h"
#include "List.h"
using namespace std;

string filename; // stores filename

void readFileData(linkedList *headNode) // reads text from a file and writes it to the AVL tree
{
  Dictionary *dict;
  string word, meaning, filename;
  fstream fin;

  cout << "\e[46mEnter the filename\x1b[0m ";
  cin >> filename;
  filename = "srcFile/" + filename + ".txt";
  fin.open(filename);
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
  string filename;
  cin >> filename;
  filename = "outputFiles/" + filename + ".txt";
  dictFile.open(filename, std::ios::app); // create/open a text file in append mode. new information is always added to the end

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

node *reverseList(node *start, node *end) // (node *start,node*end)
{
  // returns a linked list that is the reverse of the original list
  node *current, *next, *prev;

  prev = nullptr;
  end = start;
  current = start;
  while (current != NULL)
  {
    next = current->next;

    current->next = prev;

    prev = current;
    current = next;
  }
  start = prev;

  return start;
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

node *filterByLetters(node *start, char letter) //(node *start)
{
  // returns a linked list that contains only those words that have the
  node *loc, *ploc;
  ploc = start;
  node *temp;
  while (ploc != NULL)
  {
    if (is_matching(ploc, letter))
    {
      start = ploc;
      loc = ploc->next;
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
      ploc->next = loc;
      ploc = loc;
      loc = loc->next;
    }
    else
    {
      temp = loc;
      loc = loc->next;
      delete temp;
    }
  }
  ploc->next = NULL;

  return start;
}

node *rearrangeByEvenOddLength(node *start)
{
  // ploc will hold the ODD NODES AND THEIR LINKS
  // loc will hold the EVEN NODES AND THEIR LINKS
  node *oddFirst, *loc, *ploc, *sloc;
  sloc = start->next;
  ploc = start; // ODD ONE
  loc = start;  // EVEN ONE
  while (loc->data.word.length() % 2 != 0 && loc != NULL)
  {
    loc = loc->next;
  }
  while (ploc->data.word.length() % 2 == 0 && ploc != NULL)
  {
    ploc = ploc->next;
  }
  start = loc;
  oddFirst = ploc;

  while (sloc != nullptr)
  {
    if (sloc == ploc || sloc == loc)
    {
      sloc = sloc->next;
      continue;
    }
    if (sloc->data.word.length() % 2 == 0)
    {
      loc->next = sloc;
      loc = loc->next;
    }
    else
    {
      ploc->next = sloc;
      ploc = ploc->next;
    }
    sloc = sloc->next;
  }
  loc->next = oddFirst;
  ploc->next = nullptr;
  return start;
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