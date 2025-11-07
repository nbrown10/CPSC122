#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
 public:

   // Constructor
   MyString(char const* strIn);

   //
   MyString(const MyString& other);

   MyString& operator=(const MyString& other);
  // destructor 
   ~MyString();
  // Display functon
   void myDisplay() const;
  // Copy function
   void myStrcpy(char const* strIn);
  // Length function
   int myStrlen() const;

  // is equal function
   bool isEqual(char const* strIn);

  //find function
   int find(char const* strIn);

  //concat. function
   void concat(char const* strIn);

 private:

   bool isSub(char const* strIn, int idx);


   int myStrLen(char const* strIn) const;

   char* str; 
}; 
#endif