// Preston Phan
// 301 Section 1
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include <iostream>
#include "prog1.cpp"

using namespace std;

void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
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

 float amount = 0.0;

Person *personptr;
  personptr = new Person[n];

  char CustName[20];
 
 
  readData(n);
    int choice;
    do
    {
        printmenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
               Display(P,n);
                break;

            case 2:
               Deposit(P,n,CustName,amount);

                break;

            case 3:
                FindRichest(P,n);
                break;

            case 4:
                NewCopy(hello,P,n);
                break;

            case 5:
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 5);

    hello.close();
      return 0;
}
