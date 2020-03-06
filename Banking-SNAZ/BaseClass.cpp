/*BaseClass.cpp
Sedona Dionne
March 4, 2020
*/

#include "BaseClass.h"
#include <iostream>


  Base::Base() {
      entryTime.tm_min = 0;
      entryTime.tm_hour = 0;
      entryTime.tm_mday = 0;
      entryTime.tm_mon = 0;
      entryTime.tm_year = 0;
}

Base::Base() {
  double bal = balance;
}


void Base::calcDeposit(double)
{
}

void Base::calcCheck(double)
{
}

void Base::calcLate(double)
{
}

void Base::calcEarlywithdraw(double)
{
}

void Base::calcMonthInt()
{
}

void Base::displayFee()
{
}
