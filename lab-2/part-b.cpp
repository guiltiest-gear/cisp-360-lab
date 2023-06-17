// Program    : part-b.cpp
// Author     : Jade Fox
// Due Date   : June 18, 2023
// Description: Write a program that asks the uter to enter todays sales for fvie stores. The program should then
//              display a bar graph comparing each store's sales. Create each par in the graph by displaying a row of
//              asterisks. Each asterisk should represent $100 of slaes.

#include <iostream>

using std::cout, std::cin;

// Represent number of stores with a const int for readability
const int number_of_stores = 5;

// Use an array of ints to store sale numbers
int sales[number_of_stores];

// Define a method to divide by 100
int divide(int x) {
    return x / 100;
}

// Get the amount of profits per store
void sales_loop() {
    for (int i = 0; i < number_of_stores; i++) {
        cout << "Enter today's sale from store " << i + 1 << ": ";
        cin >> sales[i];
    }
    return;
}

// Display one asterisk per $100
void bar_chart() {
    // Use a char to store asterisk character to avoid confusion and ambiguity
    char asterisk = '*';
    cout << "Sales bar chart" << '\n';
    for (int i = 0; i < number_of_stores; i++) {
        cout << "Store " << i + 1 << ": ";
        for (int j = 0; j < divide(sales[i]); j++) {
            cout << asterisk;
        }
        cout << '\n';
    }
    return;
}

int main() {
    sales_loop();
    bar_chart();
    return 0;
}
