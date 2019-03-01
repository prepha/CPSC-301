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
      cout<<employees[i].fullName()<< "  "<<companyNames[i]<<endl<< " ";
   }

}

void printHighestPaid(vector<Person> &employees)
{
 float highest =0.0;
for(int l=0; l<employees.size(); l++)
{
   if(employees[l].totalPay() > highest)
   {
      highest=employees[l].totalPay();   
   }
} 

for(int j=0; j<employees.size(); j++)
{
   if(highest ==employees[j].totalPay())
    {
         cout<< "Highest Paid:" <<employees[j].fullName()<<endl;
         cout<< "Employee ID:"  <<employees[j].getEmployeeId()<<endl;
         cout<<"Employer:"  <<employees[j].getCompanyName()<<endl;
         cout<<"Total Pay: "<<highest<<endl; 
    }
}    
}


void separateAndSave(vector<Person> &employees, vector<string> &companyNames)
{
  
   

   for(int p=0; p<employees.size(); p++)
   {
      if(employees.at(p).getCompanyName() == companyNames.front())
      {
       std::fstream sup("Intel.txt");
         
         cout<<employees.at(p).fullName()<< " "<<employees.at(p).getEmployeeId()<<" "<<companyNames.at(p)<< " "<<employees.at(p).totalPay() <<endl;
         //cout<<employees.at(p).fullName()<<endl;
         /*
         sup<<employees[p].fullName()<<endl;
         sup<<employees[p].getEmployeeId()<<endl;
         sup<<employees[p].getCompanyName()<<endl;
         sup<<employees[p].totalPay()<<endl;
         */
      }  
     
      }
   }
   
    


int main()
{
 
 std::fstream hello("input.txt");
   vector<Person> employees;
   vector<string> companyNames;
   

   readData(employees);
   getCompanies(employees,companyNames);
   // printHighestPaid(employees);
    separateAndSave( employees, companyNames);
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
hello.close();
   
}
