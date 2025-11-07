/*
Name: Nathan Brown
Class: CPSC 122
Date Submitted: 10/24/2025 
Assignment 6: Linked List 2, The Next Step
*/
#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
 List lst;

 //Test PutItemT
 lst.PutItemT(10);
 lst.PutItemT(20);
 lst.PutItemT(30);
 cout << "After PutItemT is called" << endl;
 lst.Print();

 //Test for GetItemT
 cout << "Tail Item should be 30, it is: " << lst.GetItemT() << endl;

 //Test for DeleteItemT 
 lst.DeleteItemT();
 cout << "After DeleteItemT, it should remove the 30 value, it is: " << endl;
 lst.Print();

//Test for InsertItem
cout << endl << "Testing InsertItem" << endl;
 cout << "Inserting 15 in position 2" << endl;
 lst.InsertItem(2, 15);
 cout << "List should be 10 15 20" << endl;
 lst.Print();
 if (lst.GetLength() == 3)
   cout << "Correct" << endl;
 else
   cout << "Wrong" << endl;

//Test for DeleteItem
 cout << endl << "Testing DeleteItem (by value)" << endl;
 cout << "Deleting 15 from the list" << endl;
 int removed = lst.DeleteItem(15);
 cout << "List should be 10 20" << endl;
 lst.Print();
 cout << "Removed count: " << removed << endl;
 if (removed == 1)
   cout << "Correct" << endl;
 else
   cout << "Wrong" << endl;

//Test for Find
 cout << endl << "Testing Find" << endl;
 cout << "Looking for 20" << endl;
 int found = lst.Find(20);
 cout << "Should find 1 occurrence" << endl;
 cout << "Found: " << found << endl;
 if (found == 1)
   cout << "Correct" << endl;
 else
   cout << "Wrong" << endl;

//Test for copy constructor
 cout << endl << "Testing Copy Constructor" << endl;
 List lst2(lst);
 cout << "Original list:" << endl;
 lst.Print();
 cout << "Copied list:" << endl;
 lst2.Print();

 cout << "Adding 99 to copied list" << endl;
 lst2.PutItemT(99);
 cout << "Original list should stay 10 20" << endl;
 lst.Print();
 cout << "Copied list should be 10 20 99" << endl;
 lst2.Print();
 if (lst.GetLength() == 2 && lst2.GetLength() == 3)
   cout << "Correct" << endl;
 else
   cout << "Wrong" << endl;

//Test DeleteItemT
 cout << endl << "Testing DeleteItemT again" << endl;
 lst.DeleteItemT();
 cout << "Should remove 20, list should just be 10" << endl;
 lst.Print();
 if (lst.GetLength() == 1)
   cout << "Correct" << endl;
 else
   cout << "Wrong" << endl;

//Test DeleteItemH
 cout << endl << "Testing DeleteItemH" << endl;
 lst.DeleteItemH();
 cout << "Should remove 10, list should be empty" << endl;
 lst.Print();
 if (lst.IsEmpty())
   cout << "Correct" << endl;
 else
   cout << "Wrong" << endl;

 cout << endl << "All tests done." << endl;

 return 0;
}