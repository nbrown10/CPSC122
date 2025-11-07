/*
Name: Nathan Brown
Class: CPSC 122, Section 1
Date Submitted: 10/10/2025
Assignment: Project 4 
Description: Tests for class MyString
*/

#include "8-MyStr.h"
#include <iostream> 
using namespace std;

int main(int argc, char* argv[])
{
    MyString str1(argv[1]);
    MyString* str2 = new MyString(argv[1]);

    // Test of myDisplay
    // cout << "*****Test myDisplay*****" << endl;
    // cout << "static test" << endl;
    // cout << "output should be the command line input" << endl;
    // str1.myDisplay();
    // cout << endl;
    // End test of myDisplay

    // Test of myStrlen 
    // cout << "*****Test myStrlen*****" << endl;
    // cout << "dynamic test" << endl;
    // cout << "output should be length of command line input" << endl;
    // cout << str2->myStrlen() << endl;
    // cout << endl;
    // end test of myStrlen 

    // Test of myStrcpy 
    // cout << "*****Test myStrcpy*****" << endl;
    // str1.myStrcpy("HelloWorld");
    // str1.myDisplay();
    // cout << endl;
    // End test of myStrcpy 

    // Test of isEqual
    // cout << "*****Test isEqual*****" << endl;
    // cout << str1.isEqual("HelloWorld") << endl;   // should be 1
    // cout << str1.isEqual("Goodbye") << endl;      // should be 0
    // cout << endl;
    // End test of isEqual

    // Test of find 
    // cout << "*****Test find*****" << endl;
    // str1.myStrcpy("These are the days");
    // cout << str1.find("are") << endl;  // should be 6
    // cout << str1.find("not") << endl;  // should be -1
    // cout << endl;
    // End test of find 

    // Test of concat 
    // cout << "*****Test concat*****" << endl;
    // str1.myStrcpy("ABC");
    // str1.concat("DEF");
    // str1.myDisplay();  // should be ABCDEF
    // cout << endl;
    // End test of concat 



    delete str2;
    return 0;  
}
