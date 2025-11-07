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

int main()
{
 List lst1;
 List* lst2 = new List;

 //This is example Test code
 cout << "Static Declaration" << endl;
 cout << "Test PutItemH and Print" << endl;
 cout << "Correct if output is 4, 3, 2, 1, 0 on subsequent lines" << endl;
 for (int i = 0; i < 5; i++)
  lst1.PutItemT(i);
 lst1.Print();

//  cout << endl;
//  cout << "Dynamic Declaration" << endl;
//  cout << "Test PutItemH and Print" << endl;
//  cout << "Correct if output is 4, 3, 2, 1, 0 on subsequent lines" << endl;
//  for (int i = 0; i < 5; i++)
//    lst2->PutItemH(i);
//  lst2->Print();
// cout << "Is list empty? " << lst1.IsEmpty() << endl;
// cout << "Length: " << lst1.GetLength() << endl;
// cout << "Head item: " << lst1.GetItemH() << endl;

// cout << "Deleting head" << endl;
// lst1.DeleteItemH();
// lst1.Print();

// cout << endl << "Testing tail functions:" << endl;
// lst1.PutItemT(8);
// lst1.PutItemT(9);
// lst1.Print();

// cout << "Tail item: " << lst1.GetItemT() << endl;
// lst1.DeleteItemT();
// cout << "After deleting tail:" << endl;
// lst1.Print();

// cout << "Testing Find():" << endl;
// cout << "Occurrences of 2: " << lst1.Find(2) << endl;

//Destructor must be invoked on dynamically declared lists
 delete lst2;
 cout << endl;
 return 0;
}