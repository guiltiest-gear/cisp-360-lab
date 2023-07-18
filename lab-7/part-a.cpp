// Program    : part-a.cpp
// Author     : Jade Fox
// Due Date   : July 23, 2023
// Description: Design a class memberType
//              a. Each object of memberType can hold the name of a person,
//              member ID, number of books bought, and amount spent.
//              b. Include the member function to perform the various operations
//              on the objects of memberType -- for example, modify, set, and
//              show a person's name. Similarly, update, modify, and show the
//              number of books bought and the amount spent.
//              c. Add the appropriate constructors.
//              d. Write the definitions of the member functions of memberType.
//              e. Write a program to test various operations of your class
//              memberType.
//              f. Your main and your class should be in seperate inline files
//              (.cpp and .h). Failure to provide program with seperate files
//              will result in a grade of zero.

#include <cstdlib>
#include <iostream>

#include "include/membertype.h"

using std::cout, std::cin;

// Standard error function
void error_and_exit() {
  cout << "Error! That's not a valid option!\n";
  exit(1);
}

// Display user choices
void intro_output() {
  cout << "What would you like to do?\n";
  cout << "Display name of member = 1\n";
  cout << "Modify name of member = 2\n";
  cout << "Display the amount of books a member owns = 3\n";
  cout << "Modify the amount of books a member owns = 4\n";
  cout << "Display the amount of money a member has spent = 5\n";
  cout << "Modify the amount of money a member has spent = 6\n";
  cout << "Display the ID of a member = 7\n";
  cout << "Modify the ID of a member = 8\n";
  cout << "Exit the program = 9\n";
  cout << "Your choice? ";
}

// Figure out what the user wants
int user_select() {
  int choice;
  cin >> choice;
  // If the user selected 9, then exit early
  if (choice == 9) exit(0);
  // Also check if the user actually put in something valid
  if (choice <= 0 || choice >= 10) error_and_exit();
  return choice;
}

// Pick the member
int member_select() {
  int choice;
  cin >> choice;
  // Check if the user actually put in something valid
  if (choice <= 0 || choice >= 4) error_and_exit();
  return choice;
}

// User input switch
void input_switch(memberType &member, int choice) {
  switch (choice) {
    default:
      error_and_exit();
      break;
    case 1:
      member.display_name();
      break;
    case 2:
      member.mod_name();
      break;
    case 3:
      member.display_book_amount();
      break;
    case 4:
      member.mod_book_amount();
      break;
    case 5:
      member.display_spent_money();
      break;
    case 6:
      member.mod_spent_money();
      break;
    case 7:
      member.display_id();
      break;
    case 8:
      member.mod_id();
      break;
  }
}

int main() {
  bool finished = false;
  memberType member1, member2, member3;
  do {
    intro_output();
    int choice = user_select();
    cout << "Which member? [1-3]: ";
    int member = member_select();
    // Member switch statement
    switch (member) {
      default:
        error_and_exit();
        break;
      case 1:
        input_switch(member1, choice);
        break;
      case 2:
        input_switch(member2, choice);
        break;
      case 3:
        input_switch(member3, choice);
        break;
    }
  } while (finished == false);
  return 0;
}
