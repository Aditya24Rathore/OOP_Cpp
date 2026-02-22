#include <iostream>
using namespace std;

int main() {
    int Number1 = 10;
    int Number2 = 0;

    try{
        if(Number2 == 0)
              throw " Division by 0 not allowed error!!\n";
        int result = Number1/Number2;
        cout << result;
    }
    catch(const char* e) {
        cout << "exception caught" << e << endl;
    }
    return 0;
}