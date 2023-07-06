// Program    : part-b.cpp
// Author     : Jade Fox
// Due Date   : July 9, 2023
// Description: Dynamically allocate an array large enough to hold a user defined number of test scores. Once all
//              the scores are entered, the array should be passed to a function that sorts them in ascening order,
//              another to calculate the average score. Display the sorted list and average with the correct heading.
//              *Use pointer notation whenever possible.*
#include <iostream>

using std::cin, std::cout, std::swap;

// Use a global variable for length and scores because it's easier to work with
int length;
int *scores;

// Prototype the functions
float average(int *arr, int n);
void selection_sort(int *arr, int n);
void print_array(int *arr, int n);

// Selection sort, about as you expect, but converted for use with manual pointer arrays
void selection_sort(int *arr, int n) {
    // Move the boundary of the unsorted array one by one
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            // Equivalent to arr[j] < arr[min_idx]
            if (*(arr + j) < *(arr + min_idx))
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        if (min_idx != i)
            swap(*(arr + min_idx), *(arr + i));
    }
}

// Get user input for array size
void user_input() {
    cout << "How many values would you like to store? ";
    cin >> length;
    // Size up the array here
    // HACK: I know vectors exist, I know, but the point is to learn how pointers work
    scores = new int[length];
    cout << "Please input the values now:\n";
    // Input the values into the array
    for (int i = 0; i < length; i++)
        cin >> *(scores + i);
    cout << "Thank you for your input. Here are the results:\n";
}

float average(int *arr, int n) {
    float sum = 0.0, avg;
    // Go through the array and sum it
    for (int i = 0; i < n; i++)
        sum += *(arr + i);
    // Give us the sum
    avg = sum / n;
    return avg;
}

void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
    cout << '\n';
}

void display_results() {
    cout << "Sorted array: ";
    print_array(scores, length);
    cout << "Average score: " << average(scores, length) << '\n';
}

int main() {
    user_input();
    selection_sort(scores, length);
    display_results();

    // NOTE: DO NOT FORGET TO DELETE THE ARRAY, DO NOT LEAVE THIS LINE OUT OR YOU WILL REGRET IT,
    //       WE DO NOT NEED MEMORY LEAKS, DON'T EVER FORGET THIS
    delete[] scores;
    return 0;
}
