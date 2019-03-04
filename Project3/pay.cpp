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
   int n=0;
  
   float Inttotal=0.0;
    std::fstream sup("Intel.txt");
 
   for(int p=0; p<employees.size(); p++)
   { 
      if(employees.at(p).getCompanyName() == companyNames.front())
      {  
      Inttotal+=employees.at(p).totalPay();
      sup<<employees.at(p).fullName()<< " "<<employees.at(p).getEmployeeId()<<" "<<companyNames.at(p)<< " "<<employees.at(p).totalPay() <<endl;
      }
   }
   sup<<"Total:"<<" "<<Inttotal<<endl;


int s=1;
   std::fstream hello("Boeing.txt");
   float Boetotal=0.0;
   for(int k=0; k<employees.size(); k++)
   {
      if(employees.at(k).getCompanyName() == companyNames.at(s))
      { 
      //cout<<employees.at(k).fullName()<< " "<<employees.at(k).getEmployeeId()<<" "<<companyNames.at(k)<< " "<<employees.at(k).totalPay() <<endl; 
      Boetotal+=employees.at(k).totalPay();
      hello<<employees.at(k).fullName()<< " "<<employees.at(k).getEmployeeId()<<" "<<companyNames.at(k)<< " "<<employees.at(k).totalPay() <<endl; 
      }
   }
    hello<<"Total:"<<" "<<Boetotal<<endl;
     
       


   int d =2;
   std::fstream bonjour("Douglas.txt");
   float Dougtotal=0.0;
   for(int e=0; e<employees.size(); e++)
   {
      if(employees.at(e).getCompanyName() == companyNames.at(d))
      {
      //cout<<employees.at(e).fullName()<< " "<<employees.at(e).getEmployeeId()<<" "<<companyNames.at(e)<< " "<<employees.at(e).totalPay() <<endl; 
      Dougtotal+=employees.at(e).totalPay();
      bonjour<<employees.at(e).fullName()<< " "<<employees.at(e).getEmployeeId()<<" "<<companyNames.at(e)<< " "<<employees.at(e).totalPay() <<endl; 
      }
   }
   bonjour<<"Total:"<<" "<<Dougtotal<<endl;
   

int r=3;
std::fstream hola("Raytheon.txt");
float Raytotal=0.0;
for(int b=0; b<employees.size(); b++)
{
      if(employees.at(b).getCompanyName() == companyNames.at(r))
      {
          //cout<<employees.at(b).fullName()<< " "<<employees.at(b).getEmployeeId()<<" "<<companyNames.at(r)<< " "<<employees.at(b).totalPay() <<endl; 
          Raytotal+=employees.at(b).totalPay();
          hola<<employees.at(b).fullName()<< " "<<employees.at(b).getEmployeeId()<<" "<<companyNames.at(b)<< " "<<employees.at(b).totalPay() <<endl; 
      }
}
 hola<<"Total:"<<" "<<Raytotal<<endl;



 int y=8;
 std::fstream chao("HealthTech.txt");
 float Healthtotal=0.0;

 for(int u=0; u<employees.size(); u++)
{
      if(employees.at(u).getCompanyName() == companyNames.at(y))
      {
          //cout<<employees.at(u).fullName()<< " "<<employees.at(u).getEmployeeId()<<" "<<companyNames.at(u)<< " "<<employees.at(u).totalPay() <<endl; 
          Healthtotal+=employees.at(u).totalPay();
          chao<<employees.at(u).fullName()<< " "<<employees.at(u).getEmployeeId()<<" "<<companyNames.at(u)<< " "<<employees.at(u).totalPay() <<endl; 
      }
}
   chao<<"Total:"<<" "<<Healthtotal<<endl;      
      
}

    

int main()
{
 
 std::fstream hello("input.txt");
   vector<Person> employees;
   vector<string> companyNames;
   

   readData(employees);
   getCompanies(employees,companyNames);
    printHighestPaid(employees);
    separateAndSave( employees, companyNames);

hello.close();
   
}
