//list test.cpp/*
// ===========================================================
// Test 1: Copy constructor (by reference)
// -----------------------------------------------------------
// Should print the same values twice — once for the original
// list, once for the copy.
// ===========================================================
// 
/*
cout << endl << "=== Test 1: Copy constructor ===" << endl;
List lstA;
lstA.PutItemT(10);
lstA.PutItemT(20);
lstA.PutItemT(30);
cout << "Original list:" << endl;
lstA.Print();
List lstB(lstA);
cout << "Copied list:" << endl;
lstB.Print();
*/

/*
===========================================================
Test 2: InsertItem at head, middle, and tail
-----------------------------------------------------------
Should show proper insertion order.
===========================================================
*/
/*
cout << endl << "=== Test 2: InsertItem ===" << endl;
List lstC;
lstC.PutItemT(1);
lstC.PutItemT(3);
lstC.PutItemT(5);
cout << "Before insertions:" << endl;
lstC.Print();
lstC.InsertItem(1, 0);                    // insert before head
lstC.InsertItem(3, 2);                    // insert in middle
lstC.InsertItem(lstC.GetLength() + 1, 6); // insert at tail
cout << "After insertions (0 1 2 3 5 6 expected):" << endl;
lstC.Print();
*/

/*
===========================================================
Test 3: DeleteItem deletes all matches
-----------------------------------------------------------
Should remove all 20s and show correct count.
===========================================================
*/
/*
cout << endl << "=== Test 3: DeleteItem ===" << endl;
List lstD;
lstD.PutItemT(10);
lstD.PutItemT(20);
lstD.PutItemT(20);
lstD.PutItemT(30);
lstD.PutItemT(20);
cout << "Before deleting 20s:" << endl;
lstD.Print();
int removed = lstD.DeleteItem(20);
cout << "Removed " << removed << " node(s)." << endl;
cout << "After deleting 20s:" << endl;
lstD.Print();
*/

/*
===========================================================
Test 4: DeleteItem removing head and tail nodes
-----------------------------------------------------------
Checks that head/tail pointers update correctly.
===========================================================
*/
/*
cout << endl << "=== Test 4: DeleteItem (head/tail) ===" << endl;
List lstE;
lstE.PutItemT(9);
lstE.PutItemT(8);
lstE.PutItemT(9);
cout << "Before deleting 9s:" << endl;
lstE.Print();
lstE.DeleteItem(9);
cout << "After deleting 9s:" << endl;
lstE.Print();
*/
//list.cpp
//**************************************************************
// Copy Constructor: creates a deep copy of another list
//**************************************************************
List::List(List &LstIn)
{
  // Start with an empty list
  head = NULL;
  tail = NULL;
  length = 0;

  // Traverse the incoming list
  node* cur = LstIn.head;

  // Copy each item into the new list using PutItemT
  // This preserves order and updates tail automatically
  while (cur != NULL)
  {
    PutItemT(cur->item);
    cur = cur->next;
  }
}

//**************************************************************
// InsertItem: inserts a node anywhere in the list
// pos = 1 inserts before head; pos = length + 1 inserts at end
//**************************************************************
void List::InsertItem(int pos, itemType itemIn)
{
  // Make sure position is valid
  if (pos < 1 || pos > length + 1)
  {
    cout << "Invalid position." << endl;
    return;
  }

  // Create a new node and store the item
  node* tmp = new node;
  tmp->item = itemIn;

  // Case 1: insert before head
  if (pos == 1)
  {
    tmp->next = head;   // new node points to current head
    head = tmp;         // head now points to new node

    // if list was empty, tail also points to this node
    if (length == 0)
      tail = tmp;
  }
  else // Case 2: insert in middle or at tail
  {
    // Find the node before insertion point
    node* cur = head;
    for (int i = 1; i < pos - 1; i++)
      cur = cur->next;

    // Link new node into the list
    tmp->next = cur->next;
    cur->next = tmp;

    // If inserting at the very end, update tail
    if (pos == length + 1)
      tail = tmp;
  }

  // Increase list length
  length++;
}

//**************************************************************
// DeleteItem: deletes all nodes that contain target
// Returns number of nodes deleted
//**************************************************************
int List::DeleteItem(itemType target)
{
  int count = 0;

  // Case 1: delete any matches at the head
  while (head != NULL && head->item == target)
  {
    node* tmp = head;       // save pointer to old head
    head = head->next;      // move head to next node
    delete tmp;             // free old head
    count++;                // track how many deleted
    length--;               // update length
  }

  // If list is now empty, fix tail and stop
  if (head == NULL)
  {
    tail = NULL;
    return count;
  }

  // Case 2: delete matches in the rest of the list
  node* cur = head;
  while (cur->next != NULL)
  {
    if (cur->next->item == target)
    {
      node* tmp = cur->next;      // save node to delete
      cur->next = tmp->next;      // skip over deleted node

      if (tmp == tail)            // if deleting the last node
        tail = cur;               // move tail pointer back

      delete tmp;                 // free node
      count++;
      length--;
    }
    else
    {
      cur = cur->next;            // move forward if no delete
    }
  }

  return count;
}