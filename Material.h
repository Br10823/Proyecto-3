#include <iostream>
#include <string>
#include "Reservation.h"
using namespace std;

#ifndef Material_h
#define Material_h

class Material
{
  protected:
  int iMaterialID;
  string sTitle;

  public:
  Material();
  Material(int, string);
  int getMaterialID  ();
  string getTitle    ();
  void setMaterialID    (int);
  void setTitle      (string);
  virtual void toString()=0;
  virtual int numberOfDaysRented()=0;
};

Material::Material()
{
  iMaterialID = 0;
  sTitle = "Null";
}

Material::Material(int iMaterialID, string sTitle)
{
  this -> iMaterialID = iMaterialID;
  this -> sTitle      = sTitle     ;
}

int Material::getMaterialID()
{
  return iMaterialID;
}

string Material::getTitle()
{
  return sTitle;
}

void Material::setMaterialID(int iMaterialID)
{
  this -> iMaterialID = iMaterialID;
}

void Material::setTitle(string sTitle)
{
  this -> sTitle = sTitle;
}

void Material::toString()
{
  cout << "ID del material: " << iMaterialID << endl;
  cout << "Titulo: "       << sTitle      << endl;
}

#endif