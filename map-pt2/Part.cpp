#include "Part.h"


part::part()
{

}

part::part(int ID, string descrip)
{
    partID=ID;
    descr=descrip;
}

void part::setpartID(int ID)
{
    partID=ID;
}

void part::setdescr(string descrip)
{
    descr=descrip;
}

int part::getpartID()
{
    return partID;
}

string part::getdescr()
{
    return descr;
}

