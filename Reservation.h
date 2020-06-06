#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

#ifndef Reservation_h
#define Reservation_h

class Reservation
{
  private:
  int iMaterialID;
  int iClientID  ;
  Date reservationDate;

  public:
  Reservation ();
  Reservation (int, int, Date);
  int  getMaterialID ();
  int  getClientID   ();
  Date getReservDate ();
  void setMaterialID (int);
  void setClientID   (int);
  void setReservDate (Date);
  Date calculateEndOfReservation (int);
  void toString();
};


Reservation::Reservation()
{
  iMaterialID = 0;
  iClientID   = 0;
}

Reservation::Reservation(int iMaterialID, int iClientID,Date reservationDate)
{
  this -> iMaterialID = iMaterialID;
  this -> iClientID   = iClientID  ;
  this -> reservationDate = reservationDate;
}


int Reservation::getClientID ()
{
  return iClientID;
}

int Reservation::getMaterialID ()
{
  return iMaterialID;
}

Date Reservation::getReservDate ()
{
  return reservationDate;
}


void Reservation::setClientID (int iClientID)
{
  this -> iClientID = iClientID;
}

void Reservation::setMaterialID (int iMaterialID)
{
  this -> iMaterialID = iMaterialID;
}

void Reservation::setReservDate (Date reservationDate)
{
  this -> reservationDate = reservationDate;
}



Date Reservation::calculateEndOfReservation(int idays)
{
  int day, month, year, monthlimit, r, dday;
  month = reservationDate.getMonth();
  year  = reservationDate.getYear ();
  day   = reservationDate.getDay  ();
  dday  = day + idays;

  switch (month)
  {
    case 1:
    monthlimit = 31;
    break;
    case 2:
    monthlimit = 28;
    break;
    case 3:
    monthlimit = 31;
    break;
    case 4:
    monthlimit = 30;
    break;
    case 5:
    monthlimit = 31;
    break;
    case 6:
    monthlimit = 30;
    break;
    case 7:
    monthlimit = 31;
    break;
    case 8:
    monthlimit = 31;
    break;
    case 9:
    monthlimit = 30;
    break;
    case 10:
    monthlimit = 31;
    break;
    case 11:
    monthlimit = 30;
    break;
    case 12:
    monthlimit = 31;
    break;
  }

  if (dday>=monthlimit && month==12)
  {
    month = 1;
    r=monthlimit-day;
    dday= idays - r;
    year++;
  } else if (dday>=monthlimit)
  {
    month = month +1;
    r=monthlimit-day;
    dday= idays - r;
  }
  Date ddate (dday, month, year);
  cout << ddate;
  return ddate;
}

void Reservation::toString()
{
  cout << "Fecha de reservacion: " << reservationDate.getDay() << "/" << reservationDate.getMonth() << "/" << reservationDate.getYear() << endl;
  cout << "ID del material: " << iMaterialID << endl;
  cout << "ID del cliente:   " << iClientID   << endl;
}

#endif