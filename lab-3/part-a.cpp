// Program    : part-a.cpp
// Author     : Jade Fox
// Due Date   : June 25, 2023
// Description: Write a program that opens the file Random.txt, reads all of the numbers from the file, and calculates
//              the following:
//              A. The number of numbers in the file
//              B. The sum of all the numbers in the file (a running total)
//              C. The average of all the numbers in the file
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Open Random.txt
    ifstream Random("Random.txt");

    // Init the variables needed
    int counter = 0, sum = 0, number;

    // Keep going until we hit the bottom of the file
    while (!Random.eof()) {
        Random >> number;
        sum = sum + number;
        // Count up for each number in the file
        counter++;
    }

    // Display the results
    cout << "The amount of numbers in the file is " << counter - 1 << '\n'; // I need to subtract 1 because it seems to count the newline at the end of the file
    cout << "The sum of all the numbers in the file is " << sum << '\n';
    cout << "The average of all the numbers in the file is " << static_cast<float>(sum) / static_cast<float>(counter) << '\n';

    // Close Random.txt
    Random.close();
    return 0;
}
