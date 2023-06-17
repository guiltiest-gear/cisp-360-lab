// Program    : part-a.cpp
// Author     : Jade Fox
// Due Date   : June 18, 2023
// Description: Write a program that displays a menu allowing the user to select one of these four gases. After a
//              selection has been made, the user should enter the number of seconds the sound to travel in this medium
//              from its source to the location at which it was detected. The program should then report how far away
//              (in meters) the source of the sound was from the detection location.

#include <iostream>

using std::cout, std::cin;

// Use an int variable to store the choice
int choice;

// Declare seconds variable
float seconds;

// Display the gas menu
void gas_menu() {
    cout << "Medium | Speed (m/s)" << '\n';
    cout << "1. Carbon dioxide | 258.0" << '\n';
    cout << "2. Air | 331.5" << '\n';
    cout << "3. Helium | 972.0" << '\n';
    cout << "4. Hydrogen | 1,270.0" << '\n';
    cout << "Input the gas medium of your choice [1-4]: ";
    cin >> choice;
    // Detect if the user actually inputted a valid choice
    if (choice < 1 || choice > 4) {
        cout << "Error: That is not a valid selection!" << '\n';
        exit(1);
    }
    return;
}

// Ask the user the number of seconds it took the sound to travel to the detection location
void time_of_detection() {
    cout << "How much time passed until the detection of the sound (in seconds): ";
    cin >> seconds;
    // Detect if the time is less than 0 seconds or greater than 30 seconds
    if (seconds < 0.0 || seconds > 30.0) {
        cout << "Error: Times below 0 seconds or times above 30 seconds are not valid!" << '\n';
        exit(1);
    }
    return;
}

// Perform the math based on the user input
// distance = speed * time
void distance() {
    // Define the speed constants for the gasses
    const float co2 = 258.0, air = 331.5, helium = 972.0, hydrogen = 1270.0;
    switch (choice) {
        default:
            cout << "Error: Something really bad happened, this message physically should not be able to display!" << '\n';
            exit(1);
        case 1:
            cout << "The sound source is " << (co2 * seconds) << " meters away." << '\n';
            break;
        case 2:
            cout << "The sound source is " << (air * seconds) << " meters away." << '\n';
            break;
        case 3:
            cout << "The sound source is " << (helium * seconds) << " meters away." << '\n';
            break;
        case 4:
            cout << "The sound source is " << (hydrogen * seconds) << " meters away." << '\n';
            break;
    }
    return;
}

int main() {
    gas_menu();
    time_of_detection();
    distance();
    return 0;
}
