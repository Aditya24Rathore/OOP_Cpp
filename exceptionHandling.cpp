/*
 * Exception Handling Demonstration in C++
 * This program demonstrates:
 * 1. try-catch blocks for error handling
 * 2. Throwing exceptions on error conditions
 * 3. Catching specific exception types
 */

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int number1 = 150;
    int number2 = 0;

    // try-catch block: handles division by zero
    try {
        if (number2 == 0) {
            throw runtime_error("Division by 0 not allowed!");
        }

        // This line won't execute if exception is thrown
        int result = number1 / number2;
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error& e) {
        cout << "Exception Caught: " << e.what() << endl;
    }

    return 0;
}