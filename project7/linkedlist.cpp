#include "linkedlist.h"

linkedlist::linkedlist() 
{
    
 
}

linkedlist::~linkedlist() {
    // RECURSIVE
}
 
int linkedlist::count() 
{
    linkedlist l;
   //int counter=0; declared in private class

     if(l.head->next==nullptr)
    {
        return counter;
    }
    else
    {
       counter++;
      l.head=l.head->next;
    
      count();
    }
    // RECURSIVE
}

void linkedlist::addToFront(int n) 
{

}

double linkedlist::average() 
{

    // uses sum and count functions
}

int linkedlist::sum() 
{
    linkedlist l;
  //  int total=0;  declared in private class
  
    if(l.head->next==nullptr)
    {
        return total;
    }
    else
    {
        total +=l.head->data;
      l.head=l.head->next;
    
      sum();
    }
    
    
    // RECURSIVE
}

void linkedlist::writeInorder(string & file)
{

}

void linkedlist::writeReversed(string & file) 
{
    // RECURSIVE
}
