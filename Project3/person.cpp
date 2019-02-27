#include "person.h"

Person::Person()
{

}

string Person::getFirstName() 
{
    return firstName;
}
void Person::setFirstName(string fName)
{
  firstName =fName;
}

string Person::getLastName()
{
    return lastName;
}

void Person::setLastName(string lName)
{
   lastName=lName;
}


int Person::getEmployeeId()
{
    return employeeID;
}

void Person::setEmployeeId(int id)
{
    employeeID=id;
}

string Person::getCompanyName()
{
    return companyName;
}

void Person::setCompanyName(string coName)
{
    companyName =coName;
}

float Person::getPayRate()
{
    return payRate;
}

void Person::setPayRate(float rate)
{
    payRate=rate;
}

float Person::getHoursWorked()
{
    return hoursWorked;
}

void Person::setHoursWorked(float hours)
{
    hoursWorked=hours;
}

float Person::totalPay()
{
    return hoursWorked*payRate;
}

string Person::fullName()
{
    return firstName + lastName;
}



