#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
class Person{
    private: 
    string firstName;
    string lastName;
    float payRate;
    float hoursWorked;

    public:
    Person();
    void setFirstName(string fName);
    string getFirstName();

    void setLastName(string lName);
    string getLastName();

    void setPayRate(float rate);
    float getPayRate();

    void setHoursWorked(float hours);
    float getHoursWorked();

    float totalPay();
    string fullName();
    
    
};
#endif
