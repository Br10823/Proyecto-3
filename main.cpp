#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "Material.h"
#include "Reservation.h"
#include "Book.h"
#include "CD.h"
#include "Software.h"
using namespace std;
 
int main()
{ 
  Reservation arrReserve[50];
  Material  *arrMaterial[20];
  Software *software;
  Book *book;
  CD *cd;
  
  Date date, date2, dateBook, dateBook2, givenDate, newDate;
  Reservation reservation;

  int materialID, numPages, duration, clientID, day, month, year, ID, numberOfDaysRented, validMaterialID;
  int i=0;
  string title, author, operatingSystem;
  char cType, decision, cOption;
  int t=0;
  int validMaterial = 0;


  ifstream ifMaterial;
  ifMaterial.open("material.txt");
  while (! ifMaterial.eof())
  {
    ifMaterial >> materialID >> title >> cType;
    switch (cType)
    {
    case 'B':
      ifMaterial >> numPages >> author;
      arrMaterial[i] = new Book(materialID,title,numPages,author);
      i++;
    break;
    case 'C':
      ifMaterial >> duration;
      arrMaterial[i] = new CD(materialID,title, duration);
      i++;
    break;
    case 'S':
      ifMaterial >> operatingSystem;
      arrMaterial[i] = new Software(materialID,title, operatingSystem);
      i++;
    break;
    } 
  }
  ifMaterial.close();

  
  int x=0;
  ifstream ifReservation;
  ifReservation.open("reservations.txt");
  while (! ifReservation.eof())
  {
    ifReservation >> day >> month >> year >> materialID >> clientID;
    date.setYear(year);
    date.setMonth(month);
    date.setDay(day);
    arrReserve[x].setReservDate(date);
    arrReserve[x].setClientID(clientID);
    arrReserve[x].setMaterialID(materialID);
    x++;

  }
  
  int d=0;
  while (d==0)
  {
  cout << " " << endl << "Selecciona una de las siguientes opciones: "  << endl;
  cout << "a) Despliega la lista de materiales: " << endl;
  cout << "b) Despliega la lista de reservaciones: " << endl;
  cout << "c) Despliega las reservaciones de un material dado: " << endl;
  cout << "d) Despliega las reservaciones de una fecha dada: " << endl;
  cout << "e) Haz una reservación: " << endl;
  cout << "f) Termina el programa: " << endl;

  cin >> decision;

  switch (decision)
  {
    case 'a':
    for (int c=0;c<20;c++)
    {
      arrMaterial[c] -> toString();
      cout << " " << endl;
    }
    break;

    case 'b':
    for (int c=0;c<50;c++)
    {
      ID = arrReserve[c].getMaterialID();
      for (int i=0; i<20; i++)
      {
        
      if (ID == arrMaterial[i]->getMaterialID())
      {
       numberOfDaysRented = arrMaterial[i]->numberOfDaysRented();
       date = arrReserve[c].getReservDate();
       date2 = date + numberOfDaysRented;
       year = date2.getYear();
       month = date2.getMonth();
       day = date2.getDay();
       arrReserve[c].toString();
       cout << "Nombre del material: " << arrMaterial[i] -> getTitle() << endl;
       cout <<"Fecha de termino: "<< day <<"/"<< month <<"/"<< year << endl;
       cout << " " << endl;
      }
      }
    }
    break;

    case 'c':

    cout << "Elige un material:"<<endl;
    cout << "Libro     (l)" << endl;
    cout << "Disco       (D)" << endl;
    cout << "Software (s)" << endl;
    cin  >> cOption;
    switch (cOption)
    {
      case 'l':
      for (int c=0; c<20; c++)
       {
        if (arrMaterial[c]->numberOfDaysRented() == 10)
        {
          for (int i=0; i<50; i++)
          {
            if (arrMaterial[c]->getMaterialID() == arrReserve[i].getMaterialID())
            {
               cout <<"Titulo: "<< arrMaterial[c]->getTitle() << endl;
               cout <<"Fecha de inicio: "<< arrReserve[i].getReservDate();
       dateBook = arrReserve[i].getReservDate();
       dateBook2 = dateBook + 10;
       year = dateBook2.getYear();
       month = dateBook2.getMonth();
       day = dateBook2.getDay();
       cout <<"Fecha de termino: "<< day <<"/"<< month <<"/"<< year << endl;
               cout << " " << endl;
            }
          }
        }
      }
      break;
      
      case 'd':
      for (int c=0; c<20; c++)
       {
        if (arrMaterial[c]->numberOfDaysRented() == 3)
        {
          for (int i=0; i<50; i++)
          {
            if (arrMaterial[c]->getMaterialID() == arrReserve[i].getMaterialID())
            {
               cout <<"Titulo: "<< arrMaterial[c]->getTitle() << endl;
               cout <<"Fecha de inicio: "<< arrReserve[i].getReservDate();
       dateBook = arrReserve[i].getReservDate();
       dateBook2 = dateBook + 3;
       year = dateBook2.getYear();
       month = dateBook2.getMonth();
       day = dateBook2.getDay();
       cout <<"Fecha de termino: "<< day <<"/"<< month <<"/"<< year << endl;
               cout << " " << endl;
            }
          }
        }
      }

      break;
      
      case 's':
      for (int c=0; c<20; c++)
       {
        if (arrMaterial[c]->numberOfDaysRented() == 1)
        {
          for (int i=0; i<50; i++)
          {
            if (arrMaterial[c]->getMaterialID() == arrReserve[i].getMaterialID())
            {
               cout <<"Titulo: "<< arrMaterial[c]->getTitle() << endl;
               cout <<"Fecha de inicio: "<< arrReserve[i].getReservDate();
       dateBook = arrReserve[i].getReservDate();
       dateBook2 = dateBook + 1;
       year = dateBook2.getYear();
       month = dateBook2.getMonth();
       day = dateBook2.getDay();
       cout <<"Fecha de termino: "<< day <<"/"<< month <<"/"<< year << endl;
               cout << " " << endl;
            }
          }
        }
      }
      break;
      
      default:
      cout << "Intente de nuevo" << endl;
    }
    break;

    case 'd':
    cout << "Por favor diga una fecha: " << endl;
    cout << "Dia"   << endl;
    cin  >> day;
    cout << "Mes" << endl;
    cin  >> month;
    cout << "Año"  << endl;
    cin  >> year;
    givenDate.setDay(day);
    givenDate.setMonth(month);
    givenDate.setYear(year);
    for (int i=0; i<50; i++)
    {
      if (givenDate==arrReserve[i].getReservDate())
      {
        for (int c=0; c<20; c++)
        {
          if (arrReserve[i].getMaterialID() == arrMaterial[c]->getMaterialID())
          {
            cout <<"Titulo: "<< arrMaterial[c]->getTitle() << endl;
            cout <<"ID del cliente: "<< arrReserve[i].getClientID() << endl;
            cout<<" "<<endl;
          }
        }
      
      }
    }

    break;

    case 'e':
    cout << "Escribe el ID del cliente: "<< endl;
    cin  >> clientID;
    cout << "Escribe el ID del material: "<< endl;
    cin  >> materialID;
    if ((materialID>=101 && materialID<=110) ||(materialID>=201 && materialID<=205)||(materialID>=301 && materialID<=305) )
    {
      validMaterialID = materialID;
      cout << "Escribe la fecha: dd mm aaaa" << endl;
      cin  >> day >> month >> year;
    } else
    {
      cout << "ID del material invalido" << endl;
    } 
    newDate.setYear(year);
    newDate.setMonth(month);
    newDate.setDay(day);
    arrReserve[x].setMaterialID(validMaterialID);
    arrReserve[x].setClientID    (clientID);
    arrReserve[x].setReservDate   (newDate);
    arrReserve[x].toString();
    x++;
    break;
    
    case 'f':
        ofstream ofwrite;
		ofwrite.open("reservations.txt");
    
		for (int iX = 0; iX < x ;iX++)
		{
			day = arrReserve[iX].getReservDate().getDay();
			month = arrReserve[iX].getReservDate().getMonth();
			year = arrReserve[iX].getReservDate().getYear();

			materialID = arrReserve[iX].getMaterialID();
			clientID = arrReserve[iX].getClientID();
		
			ofwrite << day << " " << month << " " << year << " " << materialID << " " << clientID;
      
			if(iX != i-1)
			{
				ofwrite << "\n";
			}
      
      

		}
    ofwrite.close();
    d++;
    break;
  }
  }




  return 0;
}       
