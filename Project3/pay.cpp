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
    vector<Person>::iterator it;


std::fstream hello("input.txt");


int count=0;
Person ok;

while(hello>>firstName>>lastName>>employeeID>>companyName>>hoursWorked>>payRate)
{
  ok.setFirstName(firstName);
  ok.setLastName(lastName);
  ok.setEmployeeId(employeeID);
  ok.setCompanyName(companyName);
  ok.setHoursWorked(hoursWorked);
  ok.setPayRate(payRate);

   employees.push_back(ok);
   count++;
}
cout<<count<<endl;
/*
for(int i=0; i<employees.size();i++)
{
  employees.at(i).setFirstName(firstName);
  employees.at(i).setLastName(lastName);
  employees.at(i).setEmployeeId(employeeID);
  employees.at(i).setCompanyName(companyName);
  employees.at(i).setHoursWorked(hoursWorked);
  employees.at(i).setPayRate(payRate);
}
*/
  for(int k=0; k<employees.size(); k++)
  {
   cout<<employees.at(k).fullName()<<endl;
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
   

    readData(employees);
   //getCompanies(employees,companyNames);
   //void printHighestPaid(vector<Person> employees);
   //void separateAndSave(vector<Person> employees, vector<string> companyNames);
/*
if(employees.empty())
{
   employees.push_back(ok);
   employees.push_back(ok);
   employees.push_back(ok);
   employees.push_back(ok);
   employees.push_back(ok);
}
*/

   
}
