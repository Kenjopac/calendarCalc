/*******************************************
  Write a program that, given a month and year (like 6 2016), prints a calendar, such as

     June 2016
Su Mo Tu We Th Fr Sa
          1  2  3  4
 5  6  7  8  9 10 11
12 13 14 15 16 17 18
19 20 21 22 23 24 25
26 27 28 29 30

You may use the information provided in the assignment on zyBooks. You MUST NOT use any other material from the internet. Violation will be considered as cheating!
Make a helper function (printHeader) to print the header and a helper function (printRow) to print each row.
(1)You must include appropriate identification requirements in your program.
(2)You must provide the required functions and allow the user to repeat printing calendar.
(3)Your program must be properly documented.
(4)Your program must be completed and submitted before the deadline.
********************************************/
#include <iostream>
using namespace std;
int Month, Year;
void paramloop(){
  bool loop = true;
  int month, year;
  while(loop){
    std::cout << "give month/date format IE, 6 2016: ";
    cin>> month >>year;
    if (cin.fail() || month > 12 || month < 1 || year < 1){
      cout<<"invalid format, 1 <= month <= 12, year > 1"<<endl;
    }else{
      loop = false;
    }
  }
  Month = month;
  Year = year;
}
int LeapYears(int year){
  if (year >= 46){
  int fourHundredDivisible = year / 400;
  int oneHundredDivisible = year / 100;
  int fourDivisible = year /4;
  return fourDivisible - oneHundredDivisible + fourHundredDivisible;
    }
  else{
    return 0;
  }
}

int isLeapYear(int year){
  if (year >= 46){
  if (year % 4 == 0){
    if (year % 100 == 0){
      if (year % 400 == 0){
        return true;
      }else{
        return false;
      }
    } else{
      return true;
    }  
  } else{
    return false;
  }
  } else{
    return false;
  }
}

int nDaysInMonth(int month, int year){
  int numberofDays = 0;
  if (isLeapYear(year) == true && month == 2){
    numberofDays = 29;
  } else if (isLeapYear(year) == false && month == 2){
    numberofDays = 28;
  }
  switch (month){
    case 1: case 3: case 5: case 7: case 8:case 10: case 12:
    numberofDays = 31;
    break;
    case 4: case 6: case 9: case 11:
    numberofDays = 30;
    break;
  }
  return numberofDays;
}//crude Dictionary of days in each month 

int daysPrior(int month, int year){
  int daysPrior = 0;
  for (int i = 0; i < month; i ++){
    daysPrior += nDaysInMonth(i, year);
  }
  return daysPrior;
} // returns days prior to current month

string dayToWords(int day){
  string nameOfWeek;
  switch(day){
    case 0:
    nameOfWeek = "Sunday";
    break;
    case 1:
    nameOfWeek = "Monday";
    break;
    case 2:
    nameOfWeek = "Tuesday";
    break;
    case 3:
    nameOfWeek = "Wedsnesday";
    break;
    case 4:
    nameOfWeek = "Thursday";
    break;
    case 5:
    nameOfWeek = "Friday";
    break;
    case 6:
    nameOfWeek = "Saturday";
    break;
    default:
    nameOfWeek = "failed";
    break;
  }
  return nameOfWeek;
}

int DayoftheWeekCalculation(int month, int year){
  int nLeapYears = LeapYears(year); //add this to shift for februaries
  int dayswithoutleapyear = ( year - 1 )* 365;
  int ndaysPrior = daysPrior(month, year);
  int totalDaysSinceZero = dayswithoutleapyear + nLeapYears + ndaysPrior + 6;// 6 for saturday as 01/01/0001
  
  return totalDaysSinceZero % 7;
}
int d(int month, int year){
  int nLeapYears = LeapYears(year); //add this to shift for februaries
  int dayswithoutleapyear = (year  - 1) * 365;
  int ndaysPrior = daysPrior(month, year);
  int totalDaysSinceZero = dayswithoutleapyear + nLeapYears + ndaysPrior;// 5 for saturday as 01/01/0001
  
  return totalDaysSinceZero;
}

int main() {
  while (true){
    paramloop();
  cout<<"total days: "<<d(Month, Year)<<endl;
  cout<< "weekday is "<< dayToWords(DayoftheWeekCalculation(Month, Year))<< endl;
  cout<<"Total Leap Years : "<< LeapYears(Year)<<endl;
  cout<<DayoftheWeekCalculation(Month, Year)<<endl;
  }
}