/*
 * Exception Handling Demonstration in C++
 * This program demonstrates:
 * 1. try-catch blocks for error handling
 * 2. Throwing custom exceptions
 * 3. Catching specific exception types
 */

#include <iostream>
using namespace std;

int main() {
    // Test variables for division operation
    int Number1 = 10;
    int Number2 = 0;

    // TRY-CATCH BLOCK: Exception handling mechanism
    try{
        // Check for division by zero condition
        // THROWING EXCEPTION: When error condition is detected
        if(Number2 == 0)
              throw " Division by 0 not allowed error!!\n";  // Throw string literal
        
        // This line won't execute if exception is thrown
        int result = Number1/Number2;
        cout << result;
    }
    
    // CATCHING EXCEPTION: Handle the thrown exception
    catch(const char* e) {  // Catch string literal exceptions
        cout << "Exception Caught" << e << endl;
    }
    
    return 0;
}