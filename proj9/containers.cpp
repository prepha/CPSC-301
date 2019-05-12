#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include "Student.h"
#include <string>
#include <string.h>
using namespace std;                

//stack and queue dont have iterators

void readData(std::vector<Student> & vec) {
    std::ifstream file;
    file.open("input.txt");
    std::string fn, ln, emptyspace;
    int id;
    float test1, test2, test3, test4, test5;
    

    while(file>>fn>>ln>>id) {

        getline(file,emptyspace);
        file >> test1 >> test2 >> test3 >> test4 >> test5;
        //std::cout << fn << " " << ln << " " << id << " " << test1 << " " << test2 << " " << test3 << " " << test4 << " " << test5<<std::endl;
       
        float grade=(test1+test2+test3+test4+test5)/5; //done by me
        cout<<fn << " " << ln << " "<<grade<<std::endl;
        Student ok;
       // ok.setfirstName(fn);
        //ok.setLastName(ln);
        //ok.setStudentId(id);
        //ok.setClassGrade(grade);

     Student ello(fn,ln,id,grade);
        vec.push_back(ello);
}

    for(int i=0; i<vec.size();i++)
    {
     // cout<<vec[i].getFirstName()<<endl;
      // cout<<vec[i].getClassGrade()<<endl;
       if(vec[i].getClassGrade() >80)
       {
           cout<<vec[i].getFirstName()<<endl;
       }
    }
}

void readData(std::stack<Student> & stackz)  // stack doesnt have iterator
{
     std::ifstream file;
    file.open("input.txt");
    std::string fn, ln,emptyspace;
    int id;
    float test1, test2, test3, test4, test5;
      
   // file >> fn;
    while(file>>fn>>ln>>id) {
        getline(file,emptyspace);
        file >> test1 >> test2 >> test3 >> test4 >> test5;
        //std::cout << fn << " " << ln << " " << id << " " << test1 << " " << test2 << " " << test3 << " " << test4 << " " << test5<<std::endl;
       
        float grade=(test1+test2+test3+test4+test5)/5; //done by me
          cout<<fn << " " << ln << " "<<grade<<std::endl;
        Student ok;

    Student ello(fn,ln,id,grade);
     stackz.push(ello);
    }

    cout<<stackz.size()<<endl;
    stackz.pop();
     cout<<stackz.size()<<endl;
      cout<<stackz.top().getFirstName(); 

        
}

void readData(std::queue<Student> & q)  // queue has no iterators
{
     std::ifstream file;
    file.open("input.txt");
    std::string fn, ln, emptyspace;
    int id;
    float test1, test2, test3, test4, test5;

    while(file>>fn>>ln>>id) {

        getline(file,emptyspace);
        file >> test1 >> test2 >> test3 >> test4 >> test5;
        //std::cout << fn << " " << ln << " " << id << " " << test1 << " " << test2 << " " << test3 << " " << test4 << " " << test5<<std::endl;
       
        float grade=(test1+test2+test3+test4+test5)/5; //done by me
        cout<<fn << " " << ln << " "<<grade<<std::endl;
        Student ok;

     Student ello(fn,ln,id,grade);
        q.push(ello);
}
cout<<q.front().getFirstName()<<endl;
cout<<q.back().getFirstName()<<endl;

}

void readData(std::list<Student> & list) 
{
     std::ifstream file;
    file.open("input.txt");
    std::string fn, ln, emptyspace;
    int id;
    float test1, test2, test3, test4, test5;
    

    while(file>>fn>>ln>>id) {

        getline(file,emptyspace);
        file >> test1 >> test2 >> test3 >> test4 >> test5;
        //std::cout << fn << " " << ln << " " << id << " " << test1 << " " << test2 << " " << test3 << " " << test4 << " " << test5<<std::endl;
       
        float grade=(test1+test2+test3+test4+test5)/5; //done by me
       // cout<<fn << " " << ln << " "<<grade<<std::endl;
        Student ok;

     Student ello(fn,ln,id,grade);
        list.push_back(ello);
   
    }
   // cout<<list.size();

    std::list<Student>::iterator itr;
   
    for(itr=list.begin(); itr!=list.end();itr++)
    {
    //    cout<<itr->getFirstName()<<endl;
        if(itr->getClassGrade() >90)
        {
            cout<<itr->getFirstName()<<endl;
        }
    }
     

}

void readData(std::map<int, Student> & m) 
{
    fstream hello;
    hello.open("input.txt");
    string fname,lname,emptyspace;
    int id;
    float test1,test2,test3,test4,test5;
    while(hello>>fname>>lname>>id)
    {
        getline(hello,emptyspace);
        hello>>test1>>test2>>test3>>test4>>test5;
        //std::cout << fname << " " << lname << " " << id << " " << test1 << " " << test2 << " " << test3 << " " << test4 << " " << test5<<std::endl;
        float grade=(test1+test2+test3+test4+test5)/5; 
        cout<<fname << " " << lname << " "<<grade<<std::endl;
    }
     float grade=(test1+test2+test3+test4+test5)/5; 
    Student ello(fname,lname,id,grade);
     m.insert(pair<int,Student>(id,ello));
     std::map<int, Student>::iterator it;
   //cout<<"Enter studend id:"<<endl;
     
    for(it=m.begin(); it!=m.end();it++)
    {
        if(it->first ==id)
        {
            cout<<"hello"<<endl;
        }
      
    }
}



int main() {
    std::vector<Student> studentVec;
    std::stack<Student> studentStack;
    std::queue<Student> studentQueue;
    std::list<Student> studentList;
    std::map<int, Student> studentMap; // use the student ID for the key

   // readData(studentVec);
  //  readData(studentStack);
  // readData(studentQueue);
   // readData(studentList);
    readData(studentMap);

    
    return 0;
}
