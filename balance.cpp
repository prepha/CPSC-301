#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

struct Person
{
char Name[20];
float balance;
};


void Display(Person P[],int n)
{
  std::fstream hello;
  hello.open("data.txt");
 
 string name1;
 string name2;
 string sname;
 float num;

 Person ok;
  for(int i =0; i<n; i++)
  {
    hello>>name1;
    hello>>name2;
   
    hello>>num;

    sname = name1 + " " + name2;
    
    strcpy(P[i].Name,sname.c_str());
    P[i].balance=num;
    cout<<P[i].Name<< " ";
    cout<<P[i].balance<<endl;

   
  }
  hello.close();  
}

void FindRichest(Person P[], int n)
{
  std::fstream hello;
  hello.open("data.txt");

  float balance =0.0;
  
  for(int i=0; i<n; i++)
  {
    if(P[i].balance> balance)
    {
      balance=P[i].balance;
    }
  }
  
  for(int i =0; i<n; i++)
  {
    if(balance ==P[i].balance)
    {
      cout<<"Person with highest value is "<<P[i].Name<<endl;
    }
  }
  hello.close();

}


//void Deposit(char* CustName, Person P[],int n)
void Deposit(Person P[], int n,char *CustName, float amount)
{
 std::fstream hello; 

 cout<<"Enter Full name to deposit:";
 cin.getline(CustName,20);

 cout<<"How much would you like to deposit"<<endl;
 cin>>amount;
 
  for (int i=0; i<n; i++)
  {
    if(strcmp(CustName,P[i].Name) == 0)
    {
        amount+=P[i].balance; 
        P[i].balance=amount;
    }
   
  }
cout<<"Their new balance is " <<amount<<endl;

}

void NewCopy(std::fstream& hello,Person P[],int n)
{
  for(int i=0; i<n; i++)
  {
    hello<<P[i].Name;
    hello<<P[i].balance;

    cout<<P[i].Name<< " ";
    cout<<P[i].balance<<endl;
  }
} 
 
 Person *readData(int &n)
{
  Person *personptr;
  personptr = new Person[n];
  std::fstream hello;
  hello.open("data.txt");
 
 string name1;
 string name2;
 string sname;
 float num;

 Person ok;
  for(int i =0; i<n; i++)
  {
    hello>>name1;
    hello>>name2;
    hello>>num;
    
    sname = name1 + " " + name2;
    
    strcpy(personptr[i].Name,sname.c_str());
    personptr[i].balance=num;
    cout<<personptr[i].Name<< " ";
    cout<<personptr[i].balance<<endl;
  }
  return personptr;
  hello.close();  
}

int main()
{
  
  std::fstream hello;
  hello.open("data.txt");
  Person ok;
  int entry = 0;
   while(!hello.eof())    
      {
      hello>>ok.Name;
      hello.getline(ok.Name, 20);
       entry++;
  }
int n =entry;


 Person P[n];
// Person arr[n];
 float amount = 0.0;
 

Person *personptr;
  personptr = new Person[n];
 

  //personptr=P[n];

  


  char CustName[20];
  Display(P,n);
  FindRichest(P,n);
 // Deposit(CustName,P,n);
  Deposit(P,n,CustName,amount);
  NewCopy(hello,P,n);
  readData(n);



  hello.close();


}
