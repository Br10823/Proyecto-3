#include <iostream>
#include <string>
#include "Material.h"
using namespace std;

#ifndef Book_h
#define Book_h

class Book : public Material
{
  private:
  int iNumOfPages;
  string sAuthor;

  public:
  Book ();
  Book (int, string, int, string);
  int getNpages    ();
  string getAuthor ();
  void setNpages (int);
  void setAuthor (string);
  void toString ();
  int numberOfDaysRented();
};

Book::Book():Material()
{
  iNumOfPages = 0;
  sAuthor     = "Null";
}

Book::Book(int iMaterialID, string sTitle, int iNumOfPages, string sAuthor):Material(iMaterialID, sTitle)
{
  this -> iNumOfPages = iNumOfPages;
  this -> sAuthor     = sAuthor    ;
}

int Book::getNpages ()
{
  return iNumOfPages;
}

string Book::getAuthor()
{
  return sAuthor;
}

void Book::setNpages (int iNumOfPages)
{
  this -> iNumOfPages = iNumOfPages;
}

void Book::setAuthor (string sAuthor)
{
  this -> sAuthor = sAuthor;
}

void Book::toString()
{
  cout << "ID material: "     << iMaterialID << endl;
  cout << "Titulo: "           << sTitle      << endl;
  cout << "Autor: "          << sAuthor     << endl;
  cout << "Numero de paginas: " << iNumOfPages << endl;
}

int Book::numberOfDaysRented()
{
  return 10;
}

#endif
