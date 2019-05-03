#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>
#include "linkedlist.cpp"

using namespace std;

void readFile(linkedlist & list, string & file) 
{
   
    ifstream infile("list.txt");
   
   int t = 0;
    while(infile>>t)
    {
      cout<<t<<endl;
    }
    
}

int main() 
{
    linkedlist list;
    string file ="list.txt";
    readFile(list,file);

   
    return 0;
}
