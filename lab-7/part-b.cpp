// Program    : part-b.cpp
// Author     : Jade Fox
// Due Date   : July 23, 2023
// Description: Design a class that will determine the monthly payment on a home
//              mortgage. The monthly payment with interest compounted monthly
//              can be calculated as follows:
//              Payment = Loan * (Rate/12) * Term / Term - 1
//              Where
//              Term = (1 + Rate/12)^(12 * Years)
//              Payment = the monthly payment
//              Loan = the dollar amount of the loan
//              Rate = the annual interest rate
//              Years = the number of years of the loan

#include <iostream>

#include "include/mortgage.h"

using std::cout;

int main() {
  Mortgage money;
  cout << "Enter your loan amount: ";
  money.get_loan();
  cout << "Enter your rate: ";
  money.get_rate();
  cout << "Enter how many years this loan will last: ";
  money.get_years();
  cout << "Your monthly payment is $" << money.set_payment() << '\n';
  return 0;
}
