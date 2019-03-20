#include "person.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include<stdio.h>

void readData(vector<Person> &ok)
{
  string fName;
  string lName;
  float rate =0.0;
  float hours=0.0;
   std::fstream hello;
  hello.open("input.txt");
  while(hello>>fName >>lName >>rate >>hours)
  {
    Person().setFirstName(fName);  
    Person().setLastName(lName);
    Person().setPayRate(rate);
    Person().setHoursWorked(hours);

    
    ok.emplace_back(Person(fName,lName,rate,hours));
   
  }

 
 hello.close();

}

void writeData(vector<Person> &ok)
{
  std::fstream sup ("output.txt");
  
 
 for(int i=0; i <ok.size(); i++)
 { 
      
     sup<<ok.at(i).fullName()<< " ";

    sup<<ok.at(i).totalPay()<<endl;

   
    cout<<ok.at(i).fullName()<< " ";
     
      cout<<ok.at(i).totalPay()<<endl;


 }
}

int main()
{

     std::fstream hello;
  hello.open("input.txt");

//Person ok[n];
 //int n =20;
 vector<Person> ok;
  
 
   readData(ok);
   writeData(ok);

 

}
