/*
Name: Nathan Brown
Class: CPSC 122, 
Date Submitted: 10/17/2025 
Assignment 5
Description: Program illustrates a simple linked list  
*/
#include <iostream>
using namespace std;

#include "1-List.h"


//Constructor
List::List()
{       
 length = 0;
 head = NULL;
}
//Destructor
List::~List()
{
  cout << "Destructing nodes." << endl;
  node* cur = head;
  node* tmp;

  while (cur != NULL)
  {
    tmp = cur;
    cur = cur->next;
    delete tmp;
  }

  head = NULL;
  length = 0;
}

void List::PutItemT(itemType itemIn)
{
 node* tmp = new node;
 tmp->item = itemIn;
 tmp->next = head;
 head = tmp;
 length++;
}
// IsEmpty
bool List::IsEmpty()
{
 return (length == 0);
}
//GetLength
int List::GetLength()
{
 return length;
}
//GetItemH
itemType List::GetItemH()
{
 if (IsEmpty())
 {
   cout << "List is empty -- cannot get head item." << endl;
   exit(1);
 }
 return head->item;
}
//DeleteItemH
void List::DeleteItemH()
{
 if (IsEmpty())
 {
   cout << "List is empty -- cannot delete head." << endl;
   return;
 }

 node* tmp = head;
 head = head->next;
 delete tmp;
 length--;
}
// void List::PutItemT(itemType itemIn)
// {
//  node* tmp = new node;
//  tmp->item = itemIn;
//  tmp->next = NULL;

//  if (IsEmpty())
//  {
//    head = tmp;
//  }
//  else
//  {
//    node* cur = head;
//    while (cur->next != NULL)
//      cur = cur->next;
//    cur->next = tmp;
//  }
//  length++;
// }

itemType List::GetItemT()
{
 if (IsEmpty())
 {
   cout << "List is empty -- cannot get tail item." << endl;
   exit(1);
 }

 node* cur = head;
 while (cur->next != NULL)
   cur = cur->next;

 return cur->item;
}

void List::DeleteItemT()
{
 if (IsEmpty())
 {
   cout << "List is empty -- cannot delete tail." << endl;
   return;
 }

 // If only one node
 if (head->next == NULL)
 {
   delete head;
   head = NULL;
 }
 else
 {
   node* cur = head;
   while (cur->next->next != NULL)
     cur = cur->next;

   delete cur->next;
   cur->next = NULL;
 }
 length--;
}


// Find


int List::Find(itemType target)
{
 int count = 0;
 node* cur = head;

 while (cur != NULL)
 {
   if (cur->item == target)
     count++;
   cur = cur->next;
 }

 return count;
}

void List::Print() 
{
 node* cur = head;
 while(cur != NULL)
  {
   cout << cur->item << endl;
   cur = cur->next;
  }
}