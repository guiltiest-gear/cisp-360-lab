#ifndef MEMBERTYPE_H
#define MEMBERTYPE_H

#include <iostream>
#include <string>
using std::cout, std::cin, std::string;
class memberType {
 private:
  // Set the default values
  string name = "I don't have a name yet! Maybe go and set one first?";
  string id = "I don't have an ID yet! Maybe go and set one first?";
  int books = 0;
  double spent_money = 0.00;

 public:
  void display_name() { cout << "This member's name is " << name << '\n'; }
  void mod_name() {
    cout << "What would you like to change this member's name to? ";
    cin >> name;
  }
  void display_book_amount() {
    cout << "This member has " << books << " in their possession" << '\n';
  }
  void mod_book_amount() {
    cout << "How many books does this member own? ";
    cin >> books;
  }
  void display_spent_money() { cout << spent_money << '\n'; }
  void mod_spent_money() {
    cout << "How much money did this member spend? ";
    cin >> spent_money;
  }
  void display_id() { cout << "This member's ID is " << id << '\n'; }
  void mod_id() {
    cout << "What would you like to change this member's ID to? ";
    cin >> id;
  }
  memberType() { cout << "Member created!" << '\n'; }
};

#endif  // !MEMBERTYPE_H
