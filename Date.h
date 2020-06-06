#include <iostream>
#include <string>
using namespace std;

#ifndef Date_h
#define Date_h
 
class Date
{
private:
       int iDay;
       int iMonth;
       int iYear;
 
public:
       Date();
       Date(int, int, int);
       int getDay();
       int getMonth();
       int getYear();
       void setDay(int);
       void setMonth(int);
       void setYear(int);
       friend void operator >> (istream&, Date&);
       friend void operator << (ostream&, Date );
       friend Date operator +  (Date,int );  
       friend bool operator == (Date,Date);
       friend bool operator >= (Date,Date);
       friend bool operator <= (Date,Date);
        bool operator >  (Date);
        bool operator <  (Date);
};
 
Date::Date()
{
       iDay = 0;
       iMonth = 0;
       iYear = 0;
}
 
Date::Date(int iDay, int iMonth, int iYear)
{
       this->iDay = iDay;
       this->iMonth = iMonth;
       this->iYear = iYear;
}
 

 
int Date::getDay()
{
       return iDay;
}
 
int Date::getMonth()
{
       return iMonth;
}
 
int Date::getYear()
{
       return iYear;
}
 


void Date::setDay(int iDay)
{
       this->iDay = iDay;
}
 
void Date::setMonth(int iMonth)
{
       this->iMonth = iMonth;
}
 
void Date::setYear(int iYear)
{
       this->iYear = iYear;
}


void operator >> (istream &is, Date &date)
{
  cout << "Escribe el dia: "   << endl;
  is  >> date.iDay;
  cout << "Escribe el mes: " << endl;
  is  >> date.iMonth;
  cout << "Escribe el año: "  << endl;
  is  >> date.iYear;
}

void operator << (ostream &os, Date date)
{
  os << date.iDay << "/" << date.iMonth << "/" << date.iYear << endl;
}


Date operator + (Date date1, int idays)
{
  int day, month, year, monthlimit, r, dday;
  month = date1.iMonth;
  year  = date1.iYear ;
  day   = date1.iDay  ;
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
  return ddate;
}


bool Date::operator > (Date date)
{
  if (iDay > date.iDay)
  {
    return true;
  } else if (iDay==date.getDay() && iMonth>date.getMonth())
  {
    return true;
  } else if (iMonth==date.getMonth() && iYear>date.getYear())
  {
    return true;
  } else return false;
}

bool Date::operator < (Date date)
{
  if (iDay < date.iDay)
  {
    return true;
  } else if (iDay==date.getDay() && iMonth<date.getMonth())
  {
    return true;
  } else if (iMonth==date.getMonth() && iYear<date.getYear())
  {
    return true;
  } else return false;
}

bool operator >= (Date date1, Date date2)
{
   if (date1.iDay >= date2.iDay && date1.iMonth >= date2.iMonth && date1.iYear >= date2.iYear)
 {
   return true;
 } else return false;
}

bool operator <= (Date date1, Date date2)
{
   if (date1.iDay <= date2.iDay && date1.iMonth <= date2.iMonth && date1.iYear <= date2.iYear)
 {
   return true;
 } else return false;
}

bool operator == (Date date1, Date date2)
{
 if (date1.iDay == date2.iDay && date1.iMonth==date2.iMonth && date1.iYear == date2.iYear)
 {
   return true;
 } else return false;
}



#endif