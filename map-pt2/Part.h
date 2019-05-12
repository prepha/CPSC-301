#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class part {
    private:

    int partID;
    string descr;

    public:

    part();
    part(int ID, string descrip);
    void setpartID(int ID);
    void setdescr(string descrip);
    int getpartID();
    string getdescr();
};


