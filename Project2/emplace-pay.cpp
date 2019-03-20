#include "person.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "person.h"


void readData(vector<Person> ok,int n)
{
  string firstName;
  string lastName;
  float payRate;
  float hoursWorked;
  
  int count=0;
 
   std::fstream hello;
  hello.open("input.txt");

 

 // ok.emplace_back(Person(firstName,lastName,payRate,hoursWorked));
 while(hello >>firstName >>lastName >> payRate >>hoursWorked)
 {
   

  Person().setFirstName(firstName);  
  Person().setLastName(lastName);
  Person().setPayRate(payRate);
  Person().setHoursWorked(hoursWorked);
  

  ok.emplace_back(Person(firstName,lastName,payRate,hoursWorked));
 // ok.emplace_back(Person().getFirstName(),Person().getLastName(),Person().getPayRate(),Person().getHoursWorked());
  
  count++;
}

 cout<<ok.at(0).getFirstName(); 
cout<<count<<endl;

  cout<<ok.size()<<endl;  


    for(int i=0; i<n; i++)
    { 

      cout<<ok.at(i).getFirstName();
      //hello >>firstName >>lastName >> payRate >>hoursWorked;
  /*
      ok.at(i).setFirstName(firstName);
      
      ok.at(i).setLastName(lastName);
     
       ok.at(i).setPayRate(payRate);
    
      ok.at(i).setHoursWorked(hoursWorked);
*/
   // ok.emplace_back(ok[i].getFirstName(),ok[i].getLastName(),ok[i].getPayRate(), ok[i].getHoursWorked());
     
     // ok.emplace_back(Person().getFirstName(),Person().getLastName(),Person().getPayRate(),Person().getHoursWorked());
      // cout<<ok.at(i).getFirstName();
      cout<<"hello";
    }
  

}

void writeData(vector<Person> ok)
{
  std::fstream sup ("output.txt");
  
 
 for(int i=0; i <ok.size(); i++)
 { 
     sup<<ok.at(i).fullName()<< " ";

    sup<<ok.at(i).totalPay()<<endl;

    cout<<ok.at(i).fullName()<< " ";

      cout<<ok.at(i).totalPay()<<endl;


      if(ok[i].fullName() == ok[i+1].fullName())
      {
        break;
      }
   
 }
}

int main()
{

     std::fstream hello;
  hello.open("input.txt");

//Person ok[n];
 int n =20;
 vector<Person> ok;
  
 
   readData(ok,n);
   writeData(ok);

  hello.close();

}
