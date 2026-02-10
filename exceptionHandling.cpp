#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 0;

    try{
        if(b == 0)
              throw " division by 0 not allowed error!!\n";
        int result = a/b;
        cout << result;
    }
    catch(const char* e) {
        cout << "exception caught" << e << endl;
    }
    return 0;
}