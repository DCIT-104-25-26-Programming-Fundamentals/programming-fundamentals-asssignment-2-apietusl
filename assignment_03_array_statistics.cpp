// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Function prototypes
int getSum(int arr[], int n);
double getAverage(int arr[], int n);
int getMax(int arr[], int n);
int getMin(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n;

    cout << "Enter number of elements (max " << MAX_SIZE << "): ";
    cin >> n;

    // Validate size
    if (n <= 0 || n > MAX_SIZE) {
        cout << "Invalid size. Please enter a value between 1 and " << MAX_SIZE << "." << endl;
        return 1;
    }

    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Compute and display statistics
    cout << "\n--- Statistics ---" << endl;
    cout << "Sum:     " << getSum(arr, n) << endl;
    cout << "Average: " << getAverage(arr, n) << endl;
    cout << "Maximum: " << getMax(arr, n) << endl;
    cout << "Minimum: " << getMin(arr, n) << endl;

    return 0;
}

// Returns the sum of all elements
int getSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Returns the average of all elements
double getAverage(int arr[], int n) {
    return static_cast<double>(getSum(arr, n)) / n;
}

// Returns the maximum element
int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

// Returns the minimum element
int getMin(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];
    }
    return minVal;
}
