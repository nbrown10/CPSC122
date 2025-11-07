/*
Name: Nathan Brown
Class: CPSC 122
Date Submitted: 10/24/2025 
Assignment 6: Linked List 2, The Next Step
*/
#include <iostream>
using namespace std;

#include "2-List.h"


//Constructor
List::List()
{       
 length = 0;
 head = NULL;
 tail = NULL;
}
//Destructor
List::~List()
{
  cout << "Destructing nodes." << endl;
  while (length > 0){
    DeleteItemH();
  }

}
//PutItemH
void List::PutItemH(itemType itemIn)
{
 node* tmp = new node;
 tmp->item = itemIn;
 tmp->next = head;
 head = tmp;
 //fixed
 if (length == 0){
  tail = tmp;
 }
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
//fixed
 if (length == 0){
  tail = NULL;
 }
}
//PutItemT
void List::PutItemT(itemType itemIn)
{
 node* tmp = new node;
 tmp->item = itemIn;
 tmp->next = NULL;

 if (IsEmpty())
 {
   head = tmp;
   tail =tmp;
 }
 else
 {
    tail->next = tmp;
    tail = tmp;
 }
 length++;
}
//GetItemT
itemType List::GetItemT()
{
 return tail->item;
}
//DeleteItemT
void List::DeleteItemT()
{
 // If only one node
 if (head==tail)
 {
   delete head;
   head = NULL;
   tail = NULL;

 }
 else
 {
   node* cur = head;
   while (cur->next!= tail)
     cur = cur->next;

   delete tail;
   tail = cur;
   tail->next= NULL;
 }
 length--;
}

List::List(List &LstIn)
{
  head = NULL;
  tail = NULL;
  length = 0;
  node* cur = LstIn.head;
  while (cur != NULL)
  {
    PutItemT(cur->item);
    cur = cur->next;
  }
}

// InsertItem
void List::InsertItem(int pos, itemType itemIn)
{
  
  if (pos < 1 || pos > length + 1)
  {
    cout << "Invalid position." << endl;
    return;
  }

  // Create a new node and store the item
  node* tmp = new node;
  tmp->item = itemIn;


  if (pos == 1)
  {
    tmp->next = head;   
    head = tmp;        
    if (length == 0)
      tail = tmp;
  }
  else 
  {
   
    node* cur = head;
    for (int i = 1; i < pos - 1; i++)
      cur = cur->next;

  
    tmp->next = cur->next;
    cur->next = tmp;
    if (pos == length + 1)
      tail = tmp;
  }
  length++;
}

// DeleteItem: deletes all nodes that contain target
int List::DeleteItem(itemType target)
{
  int count = 0;


  while (head != NULL && head->item == target)
  {
    node* tmp = head;       
    head = head->next;      
    delete tmp;             
    count++;                
    length--;               
  }


  if (head == NULL)
  {
    tail = NULL;
    return count;
  }
  node* cur = head;
  while (cur->next != NULL)
  {
    if (cur->next->item == target)
    {
      node* tmp = cur->next;      
      cur->next = tmp->next;      

      if (tmp == tail)            
        tail = cur;               

      delete tmp;                 
      count++;
      length--;
    }
    else
    {
      cur = cur->next;          
    }
  }

  return count;
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