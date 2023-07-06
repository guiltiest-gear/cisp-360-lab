// Program    : part-a.cpp
// Author     : Jade Fox
// Due Date   : July 9, 2023
// Description: Create two identical arrays of 8 integers. Display the contents of the first array, then sort with
//              ascending order bubble sort and print after each pass of the sort. Display the contents of the second
//              array, then sort with ascending order selection sort and print after each pass of the sort.
#include <iostream>

using std::cout, std::swap;

// Define array length in a constant
const int length = 8;

// Prototype the functions
// NOTE: Try and do this more in future assignments
void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void print_array(int arr[], int n);

// It's just bubble sort, not sure what to explain about this
void bubble_sort(int arr[], int n) {
    // Use an indicator to tell where the steps begin
    cout << "Array steps (for bubble sort):\n";
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                // Print every time we make a swap
                print_array(arr, n);
            }
        }

        // If we didn't swap by the inner loop, then break
        // This should only happen once we finish
        if (swapped == false)
            break;
    }
}

// And this is just selection sort, nothing to see here
void selection_sort(int arr[], int n) {
    // Use an indicator to tell where the steps begin
    cout << "Array steps (for selection sort):\n";
    // Move the boundary of the unsorted array one by one
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]);
            // Print after each pass
            print_array(arr, n);
        }
    }
}

// Print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

int main() {
    // Define arrays
    int bubble_sort_arr[length] = { 7, 6, 12, 26, 87, 18, 21, 17 };
    int selection_sort_arr[length] = { 7, 6, 12, 26, 87, 18, 21, 17 };
    /*
     * NOTE: I have no clue if I could just do something like selection_sort_arr[length] = bubble_sort_arr[length]
     *       to save on a single line of code, but that at that point, it's just splitting hairs, good enough for me
    */

    // Run the bubble sort and print the results
    bubble_sort(bubble_sort_arr, length);
    cout << "Bubble sorted array:\n";
    print_array(bubble_sort_arr, length);

    // Run the selection sort and print the results
    selection_sort(selection_sort_arr, length);
    cout << "Selection sorted array:\n";
    print_array(selection_sort_arr, length);
    return 0;
}
