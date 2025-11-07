/*
Name: Nathan Brown
Class: CPSC 122
Date Submitted: 11/7/2025 
Assignment 8: Doubly Linked Lists 
*/
#include <iostream>
using namespace std;

#include "3-ListD.h"

//All tests are controlled by a dedicated function
void TestInsert();
void TestCopyConstructor();

int main()
{
// TestInsert();
 TestCopyConstructor();
}



void TestInsert()
{
 ListD* lst = new ListD;
 for (int i = 1; i <= 5; i++)
  lst->Insert(i,i);

 cout << "test general case insert" << endl;
 cout << "Passed Insert Test 1 if 1 through 5 appear on subsequent lines" << endl;
 lst->PrintForward();
 cout << endl;

 cout << "test insert at the head" << endl;
 lst->Insert(0,1);
 cout << "Passed Insert Test 2 if 0 appears in position 1" << endl; 
 lst->PrintForward();
 cout << endl;

 cout << "test insert at the tail" << endl; 
 lst->Insert(100,7);
 cout << "Passed Insert Test 3 if 100 appears in final position" << endl; 
 lst->PrintForward();
 cout << endl;
 
 cout << "test insert within the list" << endl; 
 lst->Insert(50,5);
 cout << "Passed Insert Test 4 if 50 appears in the fifth position" << endl; 
 lst->PrintForward();
 cout << endl;
 delete lst;
}

void TestCopyConstructor()
{
 ListD* lst1 = new ListD();
 for (int i = 1; i <= 3; i++)
  lst1->Insert(i,i);

 ListD* lst2 = new ListD(lst1);
 
 cout << "Test Copy Constructor" << endl; 
 cout << "Test passed if copy is indentical to initial list" << endl; 
 cout << "Traverse inital list" << endl;
 lst1->PrintForward();
 cout << endl;
 cout << "Traverse copy" << endl;
 lst2->PrintForward();

 delete lst1;
 delete lst2;
}
void TestPrintBackward()
{
  ListD* lst = new ListD;
  for (int i = 1; i <= 5; i++)
    lst->Insert(i, i);
  cout << "PrintBackward test — should show 5 4 3 2 1" << endl;
  lst->PrintBackward();
  delete lst;
}
void TestDelete()
{
    ListD* lst = new ListD;
    for (int i = 1; i <= 5; i++)
        lst->Insert(i, i);

    cout << "Test Delete" << endl;
    cout << "Passed if 1 2 4 5 appear on separate lines" << endl;

    lst->Delete(3);
    lst->PrintForward();

    delete lst;
}