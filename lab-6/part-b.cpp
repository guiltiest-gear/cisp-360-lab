// Program    : part-b.cpp
// Author     : Jade Fox
// Due Date   : July 16, 2023
// Description: Write a program that simulates inventory bins in a warehouse.
//              Each bin holds a numer of the same type of parts. The program
//              should use a structure that keeps the following data:
//              -Description of the part kept in the bin
//              -Number of parts in the bin

#include <iostream>
#include <string>
using std::cout, std::cin, std::string;

// Store your choices here
int add_or_remove_choice, bin_choice;
bool finished;

// Struct data type for the bins
struct Bin {
  string desc;
  int quantity;
};

void AddParts(int &value) {
  int add, tmp;
  cout << "How many parts would you like to add? ";
  cin >> add;
  if ((add + value) >= 30) {
    cout << "Error! Bins can't hold more than 30 items!\n";
    exit(1);
  }
  // I know this could be an else if but I'm just making sure both checks run
  if (add < 0) {
    cout << "Error! Negative values are not accepted!\n";
    exit(1);
  }
  // HACK: For some god awful reason the values won't update unless I use this
  // janky hack to get it to work, I don't care, I'm going to bed and I will
  // never speak of this code again
  tmp = value;
  tmp += add;
  value = tmp;
}

void RemoveParts(int &value) {
  int subtract, tmp;
  cout << "How many parts would you like to remove? ";
  cin >> subtract;
  if ((value - subtract) < 0) {
    cout << "Error! You can't remove that many parts!\n";
    exit(1);
  }
  if (subtract < 0) {
    cout << "Error! Negative values are not accepted!\n";
    exit(1);
  }
  tmp = value;
  tmp -= subtract;
  value = tmp;
}

void userInput() {
  cout << "What would you like to do?\n";
  cout << "1. Add parts\n";
  cout << "2. Remove parts\n";
  cout << "3. Exit\n";
  cout << "Your choice? ";
  cin >> add_or_remove_choice;
  // Exit quickly if we picked 3
  if (add_or_remove_choice == 3)
    exit(0);
  cout << "To which bin?\n";
  cout << "Valve = 1, bearing = 2, bushing = 3, coupling = 4,";
  cout << "Flange = 5, gear = 6, gear housing = 7,";
  cout << "vacuum gripper = 8, cable = 9, rod = 10\n";
  cout << "Your choice? ";
  cin >> bin_choice;
}

int main() {
  // Create a bool to determine when to stop looping
  // Create the bins
  Bin valve, bearing, bushing, coupling, flange, gear, gear_housing,
      vacuum_gripper, cable, rod;

  // Set the desriptions and quantities
  valve.desc = "Valve";
  valve.quantity = 10;

  bearing.desc = "Bearing";
  bearing.quantity = 5;

  bushing.desc = "Bushing";
  bushing.quantity = 15;

  coupling.desc = "Coupling";
  coupling.quantity = 21;

  flange.desc = "Flange";
  flange.quantity = 7;

  gear.desc = "Gear";
  gear.quantity = 5;

  gear_housing.desc = "Gear housing";
  gear_housing.quantity = 5;

  vacuum_gripper.desc = "Vacuum gripper";
  vacuum_gripper.quantity = 25;

  cable.desc = "Cable";
  cable.quantity = 18;

  rod.desc = "Rod";
  rod.quantity = 12;

  do {
    cout << "Part desription | Number of parts in the bin" << '\n';
    cout << valve.desc << " | " << valve.quantity << '\n';
    cout << bearing.desc << " | " << bearing.quantity << '\n';
    cout << bushing.desc << " | " << bushing.quantity << '\n';
    cout << coupling.desc << " | " << coupling.quantity << '\n';
    cout << flange.desc << " | " << flange.quantity << '\n';
    cout << gear.desc << " | " << gear.quantity << '\n';
    cout << gear_housing.desc << " | " << gear_housing.quantity << '\n';
    cout << vacuum_gripper.desc << " | " << vacuum_gripper.quantity << '\n';
    cout << cable.desc << " | " << cable.quantity << '\n';
    cout << rod.desc << " | " << rod.quantity << '\n';
    userInput();

    // I can't make the damn values global, so I'm stuck with this
    // I just want to go to bed
    // I hope whoever is unfortunate enough to lay eyes on this code
    // puts me down like a horse, I know it's horrid, but if I look at
    // this any longer, I'm gonna pass away
    // My sanity is too low to deal with this excuse for code
    if (add_or_remove_choice == 1) {
      if (bin_choice == 1) {
        AddParts(valve.quantity);
      } else if (bin_choice == 2) {
        AddParts(bearing.quantity);
      } else if (bin_choice == 3) {
        AddParts(bushing.quantity);
      } else if (bin_choice == 4) {
        AddParts(coupling.quantity);
      } else if (bin_choice == 5) {
        AddParts(flange.quantity);
      } else if (bin_choice == 6) {
        AddParts(gear.quantity);
      } else if (bin_choice == 7) {
        AddParts(gear_housing.quantity);
      } else if (bin_choice == 8) {
        AddParts(vacuum_gripper.quantity);
      } else if (bin_choice == 9) {
        AddParts(cable.quantity);
      } else if (bin_choice == 10) {
        AddParts(rod.quantity);
      }
    } else if (add_or_remove_choice == 2) {
      if (bin_choice == 1) {
        RemoveParts(valve.quantity);
      } else if (bin_choice == 2) {
        RemoveParts(bearing.quantity);
      } else if (bin_choice == 3) {
        RemoveParts(bushing.quantity);
      } else if (bin_choice == 4) {
        RemoveParts(coupling.quantity);
      } else if (bin_choice == 5) {
        RemoveParts(flange.quantity);
      } else if (bin_choice == 6) {
        RemoveParts(gear.quantity);
      } else if (bin_choice == 7) {
        RemoveParts(gear_housing.quantity);
      } else if (bin_choice == 8) {
        RemoveParts(vacuum_gripper.quantity);
      } else if (bin_choice == 9) {
        RemoveParts(cable.quantity);
      } else if (bin_choice == 10) {
        RemoveParts(rod.quantity);
      }
    }
  } while (finished == false);
  return 0;
}
