// Program    : m01-lab-p1.cpp
// Author     : Jade Fox
// Due Date   : June 11, 2023
// Description: A vineyard owner is planting several new rows of grapevines, and needs to know how many grapevines to
//              plant in each row. She has determined that after measuring the length of a future row, she can use the
//              following formula to calculate the number of vines that will fit in the row, along with the trellis
//              end-post assemblies that will need to be constructed at each end of the row:
//              V = R - 2E / S
//              The terms in the formula are:
//              V is the number of grapevines that will fit in the row.
//              R is the length of the row, in feet.
//              E is the amount of space, in feet, used by and end post assembly.
//              S is the space between vines, in feet.
//              Write a program that makes the calculation for the vineyard owner. The program should ask the user to
//              input the following:
//              * The length of the row, in feet.
//              * The amount of space used by and end-post assembly, in feet.
//              * The amount of space between the vines, in feet.

#include <iostream>
using std::cout, std::cin;

// Define the variables
float row_length, end_post_space, vine_space;

// Get the input
void user_input() {
    cout << "Input the length of the row, in feet: ";
    cin >> row_length;
    cout << "Input the amount of space used by an end post assembly, in feet: ";
    cin >> end_post_space;
    cout << "Input the amount of space between vines, in feet: ";
    cin >> vine_space;
    return;
}

// Perform the math
float grapevine() {
    float total = row_length - 2 * end_post_space / vine_space;
    return total;
}

// Run everything
int main() {
    user_input();
    cout << "The total number of grapevines that will fit is " << static_cast<int>(grapevine()) << '\n';
    return 0;
}
