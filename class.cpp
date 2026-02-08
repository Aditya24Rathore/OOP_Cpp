#include <bits/stdc++.h>
using namespace std;

class Employee{
  public:
    string Name;
    string Company;
    int Age;

    void Introduction() {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
};

int main() {
    Employee employee1;
    employee1.Name = "Aditya";
    employee1.Company = "Self Study";
    employee1.Age = 22;
    employee1.Introduction();
}