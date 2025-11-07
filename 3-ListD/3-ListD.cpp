/*
Name: Nathan Brown
Class: CPSC 122
Date Submitted: 11/7/2025 
Assignment 8: Doubly Linked Lists
*/
#include <iostream>
#include <climits>
using namespace std;

#include "3-ListD.h"

ListD::ListD()
{
 InitializeVars();
}

ListD::ListD(ListD* lst)
{
 InitializeVars();
 //returns a pointer to the first node, which is what we want here
 doubleNode* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  Insert(cur->item,i);
  cur = cur->next;
 }
}

void ListD::InitializeVars()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

//how would you do this?
ListD::~ListD()
{
}

doubleNode* ListD::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 //You could also make this more efficient by choosing whether to search from the head or the
 //the tail, depending on where pos is with respect to the middle of the list. 

 doubleNode* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 
  
void ListD::Insert(itemType item, int pos)
{
 //new node goes between these two nodes
 doubleNode* insertPtA = FindPosition(pos);  
 doubleNode* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode* tmp = new doubleNode; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

void ListD::PrintForward()
{
 doubleNode*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}
void ListD::PrintBackward(){
    doubleNode* cur = tail->prev;
int i = 0;
while (i < length)
 {
    cout << cur->item << endl;
    cur = cur->next;
    i++
}
}
void ListD::Delete(int pos)
{
    doubleNode* before = FindPosition(pos);
    doubleNode* target = before->next;
    doubleNode* after = target->next;

    before->next = after;
    after->prev = before;

    delete target;
    length--;
}