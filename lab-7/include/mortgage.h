#ifndef MORTGAGE_H
#define MORTGAGE_H

#include <math.h>

#include <cstdlib>
#include <iostream>

using std::cin, std::cout;

class Mortgage {
 private:
  int years;
  int loan;
  double rate;
  double payment;

  long double calc_term() { return powl((1.0 + rate / 12.0), (12.0 * years)); }
  long double calc_payment() {
    return loan * (rate / 12.0) * calc_term() / (calc_term() - 1.0);
  }

 public:
  void get_loan() {
    cin >> loan;
    if (loan <= 0) {
      cout << "Error! Negative values are not allowed!\n";
      exit(1);
    }
  }
  void get_rate() { cin >> rate; }
  void get_years() { cin >> years; }
  long double set_payment() { return payment = calc_payment(); }
};

#endif  // !MORTGAGE_H
