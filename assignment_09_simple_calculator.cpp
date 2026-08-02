// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//79
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// ---------- Function Prototypes ----------
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
bool divide(double a, double b, double& result);
bool modulus(double a, double b, double& result);
double exponent(double base, double exp);
bool getTwoNumbers(double& a, double& b);

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 7." << endl;
            continue;
        }

        double a, b, result;
        bool ok;

        switch (choice) {
            case 1:
                if (!getTwoNumbers(a, b)) break;
                cout << fixed << setprecision(2);
                cout << "Result: " << a << " + " << b << " = " << add(a, b) << endl;
                break;

            case 2:
                if (!getTwoNumbers(a, b)) break;
                cout << fixed << setprecision(2);
                cout << "Result: " << a << " - " << b << " = " << subtract(a, b) << endl;
                break;

            case 3:
                if (!getTwoNumbers(a, b)) break;
                cout << fixed << setprecision(2);
                cout << "Result: " << a << " * " << b << " = " << multiply(a, b) << endl;
                break;

            case 4:
                if (!getTwoNumbers(a, b)) break;
                ok = divide(a, b, result);
                if (ok) {
                    cout << fixed << setprecision(2);
                    cout << "Result: " << a << " / " << b << " = " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                }
                break;

            case 5:
                if (!getTwoNumbers(a, b)) break;
                ok = modulus(a, b, result);
                if (ok) {
                    cout << fixed << setprecision(2);
                    cout << "Result: " << a << " % " << b << " = " << result << endl;
                } else {
                    cout << "Error: Cannot perform modulus by zero." << endl;
                }
                break;

            case 6:
                if (!getTwoNumbers(a, b)) break;
                cout << fixed << setprecision(2);
                cout << "Result: " << a << " ^ " << b << " = " << exponent(a, b) << endl;
                break;

            case 7:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
        }

    } while (choice != 7);

    return 0;
}

// ---------- Displays the menu ----------
void displayMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

// ---------- Reads two numbers from the user; returns false on bad input ----------
bool getTwoNumbers(double& a, double& b) {
    cout << "Enter first number : ";
    cin >> a;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number entered." << endl;
        return false;
    }

    cout << "Enter second number: ";
    cin >> b;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number entered." << endl;
        return false;
    }

    return true;
}

// ---------- Arithmetic operation functions ----------
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

bool divide(double a, double b, double& result) {
    if (b == 0) {
        return false;
    }
    result = a / b;
    return true;
}

bool modulus(double a, double b, double& result) {
    if (b == 0) {
        return false;
    }
    result = fmod(a, b);
    return true;
}

double exponent(double base, double exp) {
    return pow(base, exp);
}
