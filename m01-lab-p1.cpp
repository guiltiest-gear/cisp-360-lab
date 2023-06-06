// Program    : m01-lab-p1.cpp
// Author     : Jade Fox
// Due Date   : June 11, 2023
// Description: Kathryn bought 750 shares of stock at a price of $35.00 per share.  She must pay her stockbroker a 2
//              percent commission for the transaction.  Write a program that calculates and displays the following:
//              * The amount paid for the stock alone (without the commission).
//              * The amount of the commission.
//              * The total amount paid (for the stock plus the commission).

#include <iostream>
using std::cout;

// Declare number of shares and price of shares
constexpr int shares = 750, price = 35;

// Declare commission percent
constexpr float commission = 0.02;

// Define a method to add
constexpr int add(int x, int y) {
    return x + y;
}

// Define a method to multiply
constexpr int product(int x, int y) {
    return x * y;
}

// Define a method to calculate commission
constexpr int commission_price(int x) {
    return x * commission;
}

int main () {
    constexpr int total1 = product(shares, price);
    cout << "Total amount paid (without commission): $" << total1 << '\n';

    constexpr int total2 = commission_price(total1);
    cout << "Total commission: $" << total2 << '\n';

    constexpr float total3 = add(total1, total2);
    cout << "Total amount paid (with commission): $" << total3 << '\n';
    return 0;
}
