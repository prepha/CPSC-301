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

void readPersons(vector<Person *> &cardholders) 
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

   // return 0;
}
void readRentals(vector<Book *> & books, vector<Person *> cardholders)
{
    std::fstream bonjour;
    bonjour.open("rentals.txt");
    int bookID;
    int cardID;
  
    while(bonjour>>bookID>>cardID)   // use set person for read rentals
    {
        for(int i=0;i<books.size();i++)
        {
            if(bookID == books[i]->getId())
            {
                for(int k=0; k<cardholders.size();k++)
                {
                    if(cardID ==cardholders[k]->getId())
                    {
                        books[i]->setPersonPtr(cardholders[k]);
                    }
                }
            }
        }
       
    }  
 
}

void BookCheckout(vector<Book*> &books, vector<Person*> &cardholder)
{
    int card, bookID, index_cardholder;
    bool cardid= false;
    bool bookid = false;
    

    cout<<"Please enter Card ID:"<<endl;
    cin>>card;
  
    for(int i =0; i<cardholder.size();i++)
    {
       if(cardholder[i]->getId() == card)
       {
           cardid =true;
           index_cardholder= i;
           cout<<"Cardholder:"<<cardholder[i]->fullName();
           cout<<"Please enter Book ID:"<<endl;
            cin>>bookID; 
       }    
    }
          

for(int k =0; k<books.size(); k++)
  {
      if(books[k]->getId() ==bookID)
      {
         bookid=true;
       cout<<"Title: "<< books[k]->getTitle()<<endl;
       if(books[k]->getPersonPtr() !=nullptr)
       {
       cout<<"book is in use"<<endl;
       }
       else
       {
           cout<<"Rental completed"<<endl;
       }
       
      // cout<<books[k]->getPersonPtr()->isActive()<<endl<<books[k]->getPersonPtr()->fullName()<<endl;
     }
      
     
 }

/*
for(int i=0; i<cardholder.size();i++)
       {
           if(cardholder[i]->getId() ==cardid)
           {
           
              books[k]->setPersonPtr(cardholder[i]);
            }  //books[k]->setPersonPtr(index_cardholder);
     //   books[k]->getPersonPtr()->setActive(true);  // set active for open or close new card library cards not if book is used
       }
*/
  
if(cardid==false)
    {
        cout<<"card id not found"<<endl;
    }
if(bookid==false)
{
    cout<<"Book id not found"<<endl;
}
  
}



void BookReturn(vector<Person*> &cardholder, vector<Book*> &books)
  {
       int card, bookID;
       bool bookid;
      cout<<"Enter a book ID number to return"<<endl;
      cin>>bookID;
      for (int i=0; i<books.size();i++)
      {
          if(bookID ==books[i]->getId())
          {
              cout<<"Title:"<<books[i]->getTitle();
              books[i]->setPersonPtr(nullptr); 
               cout<<"Book returned"<<endl;       
          }
          
      }
if(bookid==false)
{
    cout<<"Book id not found"<<endl;
} 
}
void viewAvailable(vector<Book*> &books)
{
    for(int i=0;i<books.size();i++)
    {
       if(books[i]->getPersonPtr() !=nullptr)
       {
           cout<<books[i]->getId()<<endl<<books[i]->getTitle()<<endl;
           cout<<books[i]->getAuthor()<<endl<<books[i]->getCategory()<<endl;
       }
    }
}

void viewRental(vector<Book*> &books)
{
    for (int i=0;i<books.size();i++)
    {
       if(books[i]->getPersonPtr() !=nullptr)
       {
           cout<<books[i]->getId()<<endl;
           cout<<books[i]->getTitle()<<endl;
           cout<<books[i]->getAuthor()<<endl;
           cout<<books[i]->getPersonPtr()->fullName()<<endl;
           cout<<books[i]->getPersonPtr()->getId()<<endl;
       }
       
    }

}

void viewOut(vector<Book*> books, vector<Person*> cardholders)
{
    int cardID;
    cout<<"Enter card ID"<<endl;
    cin>>cardID;
    bool noBooks =true;
    int count=0;

    for(int i=0; i<books.size();i++)
    { 
       if(books[i]->getPersonPtr() !=nullptr)
        {  
         if(books[i]->getPersonPtr()->getId() ==cardID)
         {
             cout<<"Book ID:"<<books[i]->getId()<<endl;
             cout<<"Title:"<<books[i]->getTitle()<<endl;
             cout<<"Author:"<<books[i]->getAuthor()<<endl;
             noBooks=false;
         }
        }
    }    

 if(noBooks==true)
        {
            cout<<"No books checked out"<<endl;
        }
   
         
}

void newLibrary(vector<Person*> &cardholders,int nextID)
{
    string firstName, lastName;
    cout<<"Enter First Name"<<endl;
    cin>>firstName;
    cout<<"Enter Last Name"<<endl;
    cin>>lastName;

    for(int i=0; i<cardholders.size();i++)
    {
        if(cardholders[i]->getFirstName() ==firstName && cardholders[i]->getLastName()==lastName)
        {
            cout<<  "Cardholder id: is now active"  <<cardholders[i]->getId()<<endl;
            cardholders[i]->setActive(1);  
            cout<<cardholders[i]->fullName()<<endl; 
            
                
        }
        else if(i==cardholders.size()-1)
        {
             cardholders.push_back(new Person(nextID,1,firstName,lastName));
             cout<<"card ID:"<<cardholders[i+1]->getId()<<endl;
             cout<<"Cardholder:"<<cardholders[i+1]->fullName()<<endl;
             break;
        
            
        }
    }
    
}
void closeCard(vector<Person*> &cardholders)
{
    int cardID;
    string fullname,input;
    
    
    cout<<"Enter card ID:"<<endl;
    cin>>cardID;
    bool id=false;

    for(int i=0; i<cardholders.size();i++)
    {
        if(cardholders[i]->getId() ==cardID)
        {
            id=true;
            cout<<cardholders[i]->fullName()<<endl;
            cout<<"Are you sure you want to deactivate? Type in yes or no"<<endl;
            cin>>input;
            if(input =="yes")
            {
                cardholders[i]->setActive(0);
                cout<<"Card deactivated"<<endl;
            }
            else if(input =="no")
            {
                cout<<"Card still active"<<endl;
              
            }
        }
        else if(cardholders[i]->isActive() == false && cardholders[i]->getId() ==cardID)
        {
            cout<<cardholders[i]->fullName()<<endl;
            cout<<"Card ID is not active"<<endl;
            
        }
    }

if(id==false)
{
    cout<<"Card id not found"<<endl;
}

}


int main()
{
    vector<Book *> books;  // book.h
    vector<Person *> cardholders; //person.h

     readBooks(books);
     readPersons(cardholders);
     readRentals(books, cardholders);
     int nextID;

    
    
    
  int choice;
    do
    {

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
             viewAvailable(books);
                // View all available books
                break;

            case 4:
                // View all outstanding rentals
                viewRental(books);
                break;

            case 5:
                // View outstanding rentals for a cardholder
                viewOut(books,cardholders);
                break;

            case 6:
                // Open new library card
                newLibrary(cardholders,nextID);
                break;

            case 7:
                // Close library card
                closeCard(cardholders);
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
