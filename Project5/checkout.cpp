// Name
// Section #
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "book.cpp"
#include <string.h>
#include <string>
#include <sstream>

using namespace std;

void printMenu() {
    cout << "----------Library Book Rental System----------" << endl;
    cout << "1.  Book checkout" << endl;
    cout << "2.  Book return" << endl;
    cout << "3.  View all available books" << endl;
    cout << "4.  View all outstanding rentals" << endl;
    cout << "5.  View outstanding rentals for a cardholder" << endl;
    cout << "6.  Open new library card" << endl;
    cout << "7.  Close library card" << endl;
    cout << "8.  Exit system" << endl;
    cout << "Please enter a choice: ";
}
void readBooks(vector<Book *> &books)
{
    std::fstream hello;
    hello.open("books.txt");
    int bookID;
    string   title;
    string   author;
    string   category;
    string line;   // accounts for the empty spaces after each variables such as ID, title, author,category
    while(hello>>bookID)
    {
        getline(hello,line);   // reads in the white space after 16582
        getline(hello,title);
        getline(hello,author);
        getline(hello,category);
        getline(hello,line);
        books.emplace_back(new Book(bookID,title,author,category));
    }
   
}

int readPersons(vector<Person *> &cardholders) 
{
    std::fstream sup;
    sup.open("persons.txt");
    int    cardID;
    bool   active;
    string firstName;
    string lastName;
     
    while(sup>>cardID>>active>>firstName>>lastName)
    {   
        cardholders.emplace_back(new Person(cardID,active,firstName,lastName));
    }

    return 0;
}
void readRentals(vector<Book *> & books, vector<Person *> cardholders)
{
    std::fstream bonjour;
    bonjour.open("rentals.txt");
    int bookID;
    int cardID;
  
    

    while(bonjour>>bookID>>cardID) 
    {
       // books.emplace_back(bookID)
    }  
 
}

void BookCheckout(vector<Book*> &books, vector<Person*> &cardholder)
{
    int card, bookID;
    bool cardid= false;

    cout<<"Please enter Card ID:"<<endl;
    cin>>card;
  
    for(int i =0; i<cardholder.size();i++)
    {
       if(cardholder[i]->getId() == card)
       {
           cardid =true;
           cout<<"Cardholder:"<<cardholder[i]->fullName();
           cout<<"Please enter Book ID:"<<endl;
            cin>>bookID;       
           // cardholder[i]->setActive(true);
        

            cout<<cardholder[i]->fullName()<<endl<<cardholder[i]->isActive()<<endl;
       } 
    
       
    }
          

for(int k =0; k<books.size(); k++)
  {
      if(books.at(k)->getId() ==bookID)
      {
       cout<<"Title: "<< books[k]->getTitle()<<endl;
       books[k]->setPersonPtr(cardholder[k]);
       books[k]->getPersonPtr()->setActive(true); 
       cout<<"Rental completed"<<endl;
        if(books[k]->getPersonPtr()->isActive())
        {
            cout<< "book is still in use"<<endl;
        }
      }  
      
      
 }

 
    
if(cardid==false)
    {
        cout<<"card id not found"<<endl;
    }
  
}



void BookReturn(vector<Person*> &cardholder, vector<Book*> &books)
  {
       int card, bookID;
      cout<<"Enter a book ID number to return"<<endl;
      cin>>bookID;
      for (int i=0; i<books.size();i++)
      {
          if(bookID ==books[i]->getId())
          {
              cout<<"Title:"<<books[i]->getTitle();
             // cardholder[i]->isActive();
              if(cardholder[i]->isActive())
              {
               cardholder[i]->setActive(0);
               cout<<"Book returned";
              }
            
          }
          else
          {
              cout<<"Book is still in use"<<endl;
          }
          
      }
      //for book return enter in ID then use set active to false;
  }
/* You are not obligated to use these function declarations - they're just given as examples
void readBooks(vector<Book *> & myBooks) {
    return;
}

int readPersons(vector<Person *> & myCardholders) {
    return 0;
}

void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders) {
    return;
}

void openCard(vector<Person *> & myCardholders, int nextID) {
    return;
}

Book * searchBook(vector<Book *> myBooks, int id) {
    return nullptr;
}
*/

int main()
{
    vector<Book *> books;  // book.h
    vector<Person *> cardholders; //person.h
    
    
  int choice;
    do
    {
     readBooks(books);
     readPersons(cardholders);
     readRentals(books, cardholders);
     
       
        // If you use cin anywhere, don't forget that you have to handle the <ENTER> key that 
        // the user pressed when entering a menu option. This is still in the input stream.
        printMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
               BookCheckout(books,cardholders);
                // Book checkout
                break;

            case 2:
                BookReturn(cardholders,books);
                // Book return
                break;

            case 3:
                // View all available books
                break;

            case 4:
                // View all outstanding rentals
                break;

            case 5:
                // View outstanding rentals for a cardholder
                break;

            case 6:
                // Open new library card
                break;

            case 7:
                // Close library card
                break;
                
            case 8:
                // Must update records in files here before exiting the program
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 8);
      return 0;
    
 

}
