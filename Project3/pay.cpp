#include "person.cpp"
#include "person.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
using namespace std;

void readData(vector<Person> &employees)
{
    string firstName;
    string lastName;
    int    employeeID;
    string companyName;
    float  hoursWorked;
    float  payRate;

Person ok;


/*
while(hello>>firstName>>lastName>>employeeID>>companyName>>hoursWorked>>payRate)
{
   employees.push_back(ok);
   
}
 */

std::fstream hello("input.txt");
hello>>firstName>>lastName>>employeeID>>companyName>>hoursWorked>>payRate;
int entry =0;
while(getline(hello, firstName))
{
   entry++;
}
cout<<entry<<endl;

for(int m=0;m<entry;m++)
{
   employees.push_back(ok);
}

  //hello>>firstName>>lastName>>employeeID>>companyName>>hoursWorked>>payRate;
  for(int i=0; i<employees.size(); i++)
  {
    //hello>>firstName>>lastName>>employeeID>>companyName>>hoursWorked>>payRate;
     employees[i].setFirstName(firstName);
     employees[i].getFirstName();

     employees[i].setLastName(lastName);
     employees[i].getLastName();

     employees[i].setEmployeeId(employeeID);
     employees[i].getEmployeeId();

     employees[i].setCompanyName(companyName);
     employees[i].getCompanyName();

     employees[i].setHoursWorked(hoursWorked);
     employees[i].getHoursWorked();

     employees[i].setPayRate(payRate);
     employees[i].getPayRate();
  }

 
//cout<<employees.size()<<endl;
  for(int k=0; k<entry; k++)
  {
   cout<<employees[k].fullName()<<endl;
  }
 
  
}

void getCompanies(vector<Person> &employees, vector<string> &companyNames)
{
   
   for(int i=0; i<employees.size(); i++)
   {
      companyNames.push_back(employees[i].getCompanyName());
      cout<<companyNames[i]<<endl<< " ";
   }
}

void printHighestPaid(vector<Person> &employees)
{

}

void separateAndSave(vector<Person> &employees, vector<string> &companyNames)
{
    
}

int main()
{

   vector<Person> employees;
   vector<string> companyNames;
   std::fstream hello;
  hello.open("input.txt");


    readData(employees);
   // getCompanies(employees,companyNames);
   //void printHighestPaid(vector<Person> employees);
   //void separateAndSave(vector<Person> employees, vector<string> companyNames);

   hello.close();
}
