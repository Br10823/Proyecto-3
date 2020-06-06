
#include <iostream>
#include <string>
#include "Material.h"
using namespace std;

#ifndef CD_h
#define CD_h

class CD : public Material
{
  private:
  int iDuration;

  public:
  CD ();
  CD (int, string, int);
  int getDuration ();
  void setDuration (int);
  void toString ();
  int numberOfDaysRented();
};

CD::CD():Material()
{
  iDuration = 0;
}

CD::CD(int iMaterialID, string sTitle, int iDuration):Material(iMaterialID, sTitle)
{
  this -> iDuration = iDuration;
}

int CD::getDuration()
{
  return iDuration;
}

void CD::setDuration(int iDuration)
{
  this -> iDuration = iDuration;
}

void CD::toString()
{
  cout << "ID del material: "     << iMaterialID << endl;
  cout << "Titulo: "           << sTitle      << endl;
  cout << "Duracion: "        << iDuration   << endl;
}

int CD::numberOfDaysRented()
{
  return 3;
}

#endif