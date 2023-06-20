// Program    : part-b.cpp
// Author     : Jade Fox
// Due Date   : June 25, 2023
// Description: Play a game of rock paper scissors against the computer

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Init the constants
const int rock = 1, paper = 2, scissors = 3;

// Get the computer's choice
int comp_choice() {
    // Init the randomness
    srand(time(0));
    // Get the randomness
    return (rand() % 3) + 1;
}

// Make sure the choice the user put in is an actual valid choice just in case
int validate(int check) {
    // If the choice is anything else other than 1, 2, or 3, abort
    while (!(cin >> check) || (check < 1 || check > 3)) {
        cout << "Error, that is not a valid choice!" << '\n';
        exit(1);
    }
    return check;
}

// Get the input from the user
int user_choice(int num) {
    cout << "Rock, paper, scissors!" << '\n'
        << "(1) for rock, (2) for paper, (3) for scissors: ";
    num = validate(num);
    return num;
}

// Show what the computer picked
void comp_move(int comp_choice) {
    cout << "Computer picked ";
    if (comp_choice == 1) {
        cout << "Rock!";
    } else if (comp_choice == 2) {
        cout << "Paper!";
        // No need to check explicitly a third time
        // Only possible option left is scissors if all else fail
    } else {
        cout << "Scissors!";
    }
    cout << '\n';
    return;
}

// Pick the winner
void winner(int comp_choice, int user_choice, bool &play_again) { // play_again must be passed by reference
    cout << '\n';
    if (comp_choice == rock) {
        switch (user_choice) {
            case rock:
                cout << "Tie. Try again.";
                play_again = true;
                break;
            case paper:
                cout << "Player wins!";
                play_again = false;
                break;
            case scissors:
                cout << "Computer wins!";
                play_again = false;
                break;
        }
    } else if (comp_choice == paper) {
        switch (user_choice) {
            case rock:
                cout << "Computer wins!";
                play_again = false;
                break;
            case paper:
                cout << "Tie. Try again.";
                play_again = true;
                break;
            case scissors:
                cout << "Player wins!";
                play_again = false;
                break;
        }
    } else if (comp_choice == scissors) { // Although not needed, improves code clarity
        switch (user_choice) {
            case rock:
                cout << "Player wins!";
                play_again = false;
                break;
            case paper:
                cout << "Computer wins!";
                play_again = false;
                break;
            case scissors:
                cout << "Tie. Try again.";
                play_again = true;
                break;
        }
    }
    cout << '\n';
    return;
}

int main() {
    // For some god awful reason, g++ won't shut up about user_number being uninitialized
    // The code will work exactly the same, and the 0 will get overritten anyway
    // I genuinely have no clue why it does this, but I don't have the energy to care
    // At least doing this gets g++ to put a sock in it
    int comp_number, user_number = 0;
    bool play_again;

    // Test if we need to play again AFTER the fact
    do {
        comp_number = comp_choice();
        user_number = user_choice(user_number);
        comp_move(comp_number);
        winner(comp_number, user_number, play_again);
    } while (play_again == true); // Keep going until someone wins

    return 0;
}
