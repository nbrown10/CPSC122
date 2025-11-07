/*Name: Nathan Brown
Class: CPSC 122
Date:September 5, 2025
Assignment: Project 1
Description:  Program determines whether input integer is prime 
input integer whose primality is to be judged 
returns true if num is prime, false oterhwise
*/


#include <iostream>
using namespace std;
bool isPrime (int num);
void display(int totalPrimes, int cols);  //function prototype must be declared
                         //before use.  prototype includes
 //return type, function name, parameters type(s)
bool isPrime(int num) {
  if (num < 2) return false;
  for (int i =2; i < num; i++) {
	if (num % i == 0)
	return false;
 }
return true;
}
int main(int argc, char* argv[]) {
   if (argc != 3) {
	cout << "Usage: " << argv[0] << " <numPrimes> <numCols> \n";
return 1; }
 int num= atoi(argv[1]);
 int col= atoi(argv[2]);
  if (num <= 0 || col <= 0) {
	cout << "Invalid Arguments \n";
	return 1;}

 display(num,col);
 cout << endl;

 return 0; 
} 

void display(int totalPrimes, int cols)
{
 int count = 0;
 int candidate = 2;
 
 while (count < totalPrimes)
  {
   if (isPrime(candidate)) {
	cout << candidate << '\t';
	count++;
   if (count % cols == 0)  
    cout << endl;}
   candidate++;
  }
cout << endl;
}
