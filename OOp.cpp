#include <bits/stdc++.h>
using namespace std;

class AbstractionPromotion {

    virtual void AskForPromotion() = 0;

};

class Employee : AbstractionPromotion {
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

    void AskForPromotion() {

        if(Age >= 25)
            cout <<  Name << ", got the promotion!" << endl;
        else
            cout << Name << ", Sorry! No promotion for you." << endl;

    }
};

class Developer:public Employee {
    public:
        string FavProgrammingLang;
        Developer(string name, string company, int age, string favProgrammingLang)
            :Employee(name, company, age)
        {
            this->FavProgrammingLang = favProgrammingLang;
        }

        void FixBug() {
            cout << getName() << ", Fix the Bug using " << FavProgrammingLang << " language" << endl;
        }
};

class Teacher:public Employee {
    public:
        string Subject;
        void PrepareLesson() {
            cout << getName() << " is prepareing " << Subject << " lesson" << endl;
        }
        Teacher(string name, string company, int age, string subject)
            :Employee(name, company, age)
        {
            this->Subject = subject;
        }
};

int main() {
    // Employee employee1 = Employee("Aditya", "Self Study", 22);
    // employee1.Introduction();

    // Employee employee2 = Employee("Rishi", "Hostel", 21);
    // employee2.Introduction();

    // employee1.setAge(26);

    // cout << employee1.getName() << " is " << employee1.getAge() << " years old now ";

    // employee1.AskForPromotion();
    // employee2.AskForPromotion();

    // Developer d = Developer("Aditya" , "Self-Study", 22, "C++");

    // d.FixBug();
    // d.AskForPromotion();

    Teacher t = Teacher("Rishi", "UIT", 22, "IOT");
    t.PrepareLesson();

}