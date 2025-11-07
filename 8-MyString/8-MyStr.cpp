/*
Name: Nathan Brown
Class: CPSC 122, Section 1
Date Submitted: 10/10/2025
Assignment: Project 4 
Description: Tests for class MyString
*/

#include <iostream>
using namespace std;

#include "8-MyStr.h"

// Constructor
MyString::MyString(char const* strIn)
{
    int length = myStrLen(strIn);
    str = new char[length + 1];
    int i = 0;
    while(i < length)
    {
        str[i] = strIn[i];
        i++;
    }
    str[i] = '\0';
}

// Copy constructor
MyString::MyString(const MyString& other)
{
    int length = myStrLen(other.str);
    str = new char[length + 1];
    for (int i = 0; i < length; i++)
        str[i] = other.str[i];
    str[length] = '\0';
}

// operator
MyString& MyString::operator=(const MyString& other)
{
    if (this != &other) {
        delete [] str;
        int length = myStrLen(other.str);
        str = new char[length + 1];
        for (int i = 0; i < length; i++)
            str[i] = other.str[i];
        str[length] = '\0';
    }
    return *this;
}

// Destructor
MyString::~MyString()
{
    delete [] str;
}

// Displays string
void MyString::myDisplay() const
{
    cout << str << endl;
}

// Overwrites content
void MyString::myStrcpy(char const* strIn)
{
    delete [] str;
    int length = myStrLen(strIn);
    str = new char[length + 1];
    for (int i = 0; i < length; i++)
        str[i] = strIn[i];
    str[length] = '\0';
}

// Returns length 
int MyString::myStrlen() const
{
    return myStrLen(str);
}

// Compares
bool MyString::isEqual(char const* strIn)
{
    int i = 0;
    while (str[i] != '\0' && strIn[i] != '\0') {
        if (str[i] != strIn[i])
            return false;
        i++;
    }
    return (str[i] == '\0' && strIn[i] == '\0');
}

bool MyString::isSub(char const* strIn, int idx)
{
    int i = 0;
    while (strIn[i] != '\0') {
        if (str[idx + i] == '\0') return false;
        if (str[idx + i] != strIn[i]) return false;
        i++;
    }
    return true;
}


int MyString::find(char const* strIn)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == strIn[0]) {
            if (isSub(strIn, i))
                return i;
        }
    }
    return -1;
}


void MyString::concat(char const* strIn)
{
    int len1 = myStrLen(str);
    int len2 = myStrLen(strIn);
    char* temp = new char[len1 + len2 + 1];

    for (int i = 0; i < len1; i++)
        temp[i] = str[i];

    for (int j = 0; j < len2; j++)
        temp[len1 + j] = strIn[j];

    temp[len1 + len2] = '\0';

    delete [] str;
    str = temp;
}


int MyString::myStrLen(char const* strIn) const
{
    int idx = 0;
    while (strIn[idx] != '\0')
        idx++;
    return idx;
}
