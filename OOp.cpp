#include <bits/stdc++.h>
using namespace std;

class Employee{
    private:      
        string Name;
        string Company;
        int Age;

    public:

    void setName(string name) { //setter
        this->Name = name;
    }

    string getName() { //getter
        return Name;
    }

    void setAge(int age) {
        if(age >= 18)
        this->Age = age;
    }

    int getAge() {
        return Age;
    }

    void Introduction() {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }

    Employee(string name, string company, int age) {
        this->Name = name;
        this->Company = company;
        this->Age = age;
    }
};

int main() {
    Employee employee1 = Employee("Aditya", "Self Study", 22);
    employee1.Introduction();

    Employee employee2 = Employee("Rishi", "Hostel", 21);
    employee2.Introduction();

    employee1.setAge(24);

    cout << employee1.getName() << " is " << employee1.getAge() << " years old now ";
}