#include <iostream> // Read/Write to console
#include <fstream>  // Read/Write to files
#include <string>   // String class to more easily handle this data type
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include "Part.cpp"
// include your class file

using namespace std;

void readData(map<int,part> &parts)
{
    fstream hello;
    hello.open("input.txt");
    int num;
    string description,emptyspace;
    while(hello>>num)
    {
        getline(hello,emptyspace); // works
        getline(hello,description);
        cout<<num<<endl;
        cout<<description<<endl;
        part ello(num,description);
        parts.insert(pair<int,part>(num,ello));
    }
    
    //cout<<parts.size()<<endl;
}


void newPart(map<int,part> &parts)
{
    int id;
    string descrip;
    cout<<"Enter part number:";
    cin>>id;
    cout<<"Enter part description"<<endl;
    cin>>descrip;
    getline(cin,descrip);

    part ello(id,descrip);
    parts.insert(pair<int,part>(id,ello));
    
}

void findPart(map<int,part> &parts)
{
    map<int,part>::iterator itr;
    int id;
    string descrip;
    bool notfound=false;
    cout<<"Enter part number:";
    cin>>id;
    

    for(itr=parts.begin(); itr!=parts.end();itr++)
    {
        if(itr->first ==id)
        {
            cout<<"Part found"<<endl;
            notfound=true;
        }     
    }

    if(notfound==false)
    {
        cout<<"Part not found"<<endl;
    }

}
void writenew(map<int,part> &parts)
{
    fstream hello;
    hello.open("output.txt");
    map<int,part>::iterator itr;

   for(itr=parts.begin();itr!=parts.end();itr++)
   {
     
      hello<<itr->second.getpartID()<<endl;
      hello<<itr->second.getdescr()<<endl;

     
      
   }
}
char getCommand();

int main() {
    const string FILENAME = "input.txt";
    const string OUTPUTFILE = "output.txt";

    char cmd;
    
    // create empty data structure to store parts
    map<int,part> parts;
     map<int,part>::iterator it;
    // read the storage file
    readData(parts);

    
    

    do {
        cmd = getCommand();
        switch (cmd) {
            case 'n' : newPart(parts);
                    // add new part
            break;

            case 'f' : findPart(parts);
                // find part
            break;

            case 'q' : ; 
            // no extra code and no break, we want q to do the 'a' action as well

            case 'a' : writenew(parts);
            // write to output file
            break;

            default : break;
        }
    } while (cmd != 'q');
    return 0;
}

char getCommand() {
    char cmd = 'a';
    cout << endl << "Please enter one of the following commands:\n(N)ew Part\n(F)ind a Part\n(A)rchive data\n(Q)uit\n->";
    cin >> cmd;
    return tolower(cmd); // in case they enter capital letters
}
