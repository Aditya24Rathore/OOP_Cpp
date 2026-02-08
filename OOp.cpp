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

    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main() {
    Employee employee1 = Employee("Aditya", "Self Study", 22);
    employee1.Introduction();

    Employee employee2 = Employee("Rishi", "Hostel", 21);
    employee2.Introduction();
}