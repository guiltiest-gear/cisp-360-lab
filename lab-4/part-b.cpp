// Program    : part-b.cpp
// Author     : Jade Fox
// Due Date   : July 2, 2023
// Description: Write a program that has an array of at least 20 integers. Call a function that uses a linear search
//              algorithm to locate one of the values. Keep a count of the number of comparisons it makes until it
//              finds the value. Do the same exact thing with a binary search algorithm. Display the values on screen.

#include <iostream>

using std::cout;

// Define the array and the search term
const int search_number = 6, length = 20;

// For some god awful reason, I can't use const for the array
// I have no idea why, but clangd won't shut up about it when I call linear_search
int numbers[length] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

// Define the counters to be used
int linear_counter = 0, binary_counter = 0;

// Define the linear search algorithm
int linear_search(int arr[], int N, int x) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == x) {
            return i;
        }
        // Count every time we make a comparison
        linear_counter++;
    }
    return -1;
}

// Define the binary search algorithm
int binary_search(int arr[], int left, int right, int x) {
    while (left <= right) {
        // Set the midpoint
        int middle = left + (right - left) / 2;

        // Check if the value is at the middle
        if (arr[middle] == x) {
            binary_counter++;
            return middle;
        // If the middle is less than x, ignore the left half
        } else if (arr[middle] < x) {
            binary_counter++;
            left = middle + 1;
        // If the middle is greater than x, ignore the right half
        } else {
            binary_counter++;
            right = middle - 1;
        }
    }
    return -1;
}

int main() {
    linear_search(numbers, length, search_number);
    binary_search(numbers, 0, length - 1, search_number);
    cout << "Linear search found number after " << linear_counter << " comparisons.\n";
    cout << "Binary search found number after " << binary_counter << " comparisons.\n";
    return 0;
}
