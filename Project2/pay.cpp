#include "person.cpp"
#include "person.h"
#include <iostream>
#include <fstream>

void readData(Person ok[], int n)
{
  string firstName;
  string lastName;
  float payRate;
  float hoursWorked;

   std::fstream hello;
  hello.open("input.txt");
    for(int i=0; i<n; i++)
    { 
      
      hello >>firstName >>lastName >> payRate >>hoursWorked;
      ok[i].setFirstName(firstName);
      ok[i].getFirstName();
      
      ok[i].setLastName(lastName);
      ok[i].getLastName();

      ok[i].fullName();


      ok[i].setPayRate(payRate);
      ok[i].getPayRate();

      ok[i].setHoursWorked(hoursWorked);
      ok[i].getHoursWorked();

      cout<<ok[i].fullName()<< " ";

      cout<<ok[i].totalPay()<<endl;
      
    }

}

void writeData(Person ok[], int n)
{
  std::fstream hello;
  hello.open("input.txt");
 for(int i=0; i <n; i++)
 {
   hello<<ok[i].fullName();

   hello<<ok[i].totalPay();

 }

}

int main()
{
  

     std::fstream hello;
  hello.open("input.txt");

  

 int n =6;
  Person ok[n];

 
 
   readData(ok, n);
    writeData(ok, n);

  hello.close();

}
