#include <iostream>
#include <string>
#include "Material.h"
using namespace std;

#ifndef Software_h
#define Software_h

class Software : public Material
{
  private:
  string sOperatingSystem;

  public:
  Software ();
  Software (int, string, string);
  string getOperatingSystem ();
  void setOperatingSystem (string);
  void toString ();
  int numberOfDaysRented();
};

Software::Software():Material()
{
  sOperatingSystem = "Null";
}

Software::Software(int iMaterialID, string sTitle, string sOperatingSystem):Material(iMaterialID, sTitle)
{
  this -> sOperatingSystem = sOperatingSystem;
}

string Software::getOperatingSystem()
{
  return sOperatingSystem;
}

void Software::setOperatingSystem(string sOperatingSystem)
{
  this -> sOperatingSystem = sOperatingSystem;
}

void Software::toString()
{
  cout << "ID del material: "     << iMaterialID << endl;
  cout << "Titulo: "           << sTitle      << endl;
  cout << "Sistema operativo: "<< sOperatingSystem << endl;
}

int Software::numberOfDaysRented()
{
  return 1;
}


#endif