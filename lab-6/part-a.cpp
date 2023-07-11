// Program    : part-a.cpp
// Author     : Jade Fox
// Due Date   : July 16, 2023
// Description: Write a function that accepts an int array and the array's size
//              as arguments. The function should create a copy of the array,
//              except that the element values should be reverse in the copy.
//              The function should return a pointer to the new array.
//              Demonstrate the function in a complete program.

#include <iostream>
using std::cout;

// Input array, length, the start, and the end
int *rev_arr(int arr[], int n, int start, int end) {
    // Init the pointer
    int *arr_copy = new int[n];

    // Now copy the input array over to the new manual array
    // Do this in two steps just to make sure we're not attempting to allocate
    // to places that don't exist yet
    for (int i = 0; i < n; i++)
        *(arr_copy + i) = arr[i];

    // Alright, now we finally, finally do the actual reversing
    while (start < end) {
        int temp = *(arr_copy + start);
        *(arr_copy + start) = *(arr_copy + end);
        *(arr_copy + end) = temp;
        start++;
        end--;
    }

    return arr_copy;
}

// Dump the array to standard output
void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

int main() {
    // The array for testing
    int old_arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int length = sizeof(old_arr) / sizeof(old_arr[0]);
    // Doing this just saves me a line of code
    int *new_arr = rev_arr(old_arr, length, 0, length - 1);

    cout << "Original array\n";
    print_arr(old_arr, length);

    cout << "Reversed array\n";
    print_arr(new_arr, length);

    // NOTE: DO NOT FORGET ABOUT THIS LINE, AVOID MEMORY LEAKS
    delete[] new_arr;
    return 0;
}
