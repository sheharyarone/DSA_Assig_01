#include <iostream>
#include "Dictionary.h"
using namespace std;

class linkedList
{ // classs definition of Node
public:
  Dictionary data;
  linkedList *next;
  linkedList()
  {
    next = nullptr;
  }
};
// class linkedList
// {
// public:
//   node *head;
//   node *tail;
//   node *ploc;
//   node *loc;

//   linkedList()
//   {
//     head = nullptr;
//     tail = nullptr;
//     ploc = nullptr;
//     loc = nullptr;
//   }

//   bool isempty() const
//   {
//     return head == nullptr;
//   }

//   int length() const
//   {
//     node *temp = head;
//     int n = 0;

//     while (temp != nullptr)
//     {
//       n++;
//       temp = temp->next;
//     }
//     return n;
//   }

//   void insertAtHead(Dictionary dic)
//   {
//     node *newnode = new node(dic);
//     if (isempty())
//     {
//       head = newnode;
//       tail = newnode;
//     }
//     else
//     {
//       newnode->next = head;
//       head = newnode;
//     }
//   }

//   void insertAtTail(Dictionary dic)
//   {
//     node *newnode = new node(dic);
//     if (isempty())
//     {
//       head = newnode;
//       tail = newnode;
//     }
//     else
//     {
//       tail->next = newnode;
//       tail = newnode;
//     }
//   }

//   void insertAtPos(Dictionary dict, int idx)
//   {
//     if (idx == 0)
//     {
//       insertAtHead(dict);
//     }
//     else if (idx == length() - 1)
//     {
//       insertAtTail(dict);
//     }
//     else
//     {
//       node *newnode = new node(dict);
//       node *temp = head;
//       for (int i = 0; i < idx - 1; i++)
//       {
//         temp = temp->next;
//       }
//       node *n = temp->next;
//       temp->next = newnode;
//       newnode->next = n;
//     }
//   }

//   void printll() const
//   {
//     node *temp = head;
//     while (temp != nullptr)
//     {
//       cout << temp->data << endl;
//       ;
//       temp = temp->next;
//     }
//     cout << endl;
//   }

//   void insertSorted(Dictionary dict)
//   {
//     if (head == NULL)
//     {
//       insertAtHead(dict);
//       return;
//     }
//     node *temp = head;

//     int n = 0;

//     while (temp->data < dict)
//     {
//       if (temp->next == nullptr)
//       {
//         insertAtTail(dict);
//         return;
//       }
//       temp = temp->next;
//       n++;
//     }
//     insertAtPos(dict, n);
//   }
// };