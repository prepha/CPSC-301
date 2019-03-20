#include "person.cpp"
#include <iostream>
#include <fstream>
#include <vector>



void readData(vector<Person> &ok)
{
  string firstName;
  string lastName;
  float payRate =0.0;
  float hoursWorked=0.0;
   std::fstream hello;
  hello.open("input.txt");
  while(hello >>firstName >>lastName >> payRate >>hoursWorked)
  {
    Person().setFirstName(firstName);  
    Person().setLastName(lastName);
    Person().setPayRate(payRate);
    Person().setHoursWorked(hoursWorked);
    ok.emplace_back(Person(firstName,lastName,payRate,hoursWorked));
  }

 
 hello.close();

}

void writeData(vector<Person> &ok)
{
  std::fstream sup ("output.txt");
  
 
 for(int i=0; i <ok.size(); i++)
 { 
      sup<<ok.at(i).getFirstName();
      sup<<ok.at(i).getLastName();

     sup<<ok.at(i).fullName()<< " ";

    sup<<ok.at(i).totalPay()<<endl;

    cout<<ok.at(i).getFirstName()<<endl;

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
