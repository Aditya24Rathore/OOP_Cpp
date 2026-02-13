#include <bits/stdc++.h>
using namespace std;

class AbstractionPromotion {

    virtual void AskForPromotion() = 0;

};

class Employee : AbstractionPromotion {

    private:      

        string Company;
        int Age;

    protected:

        string Name;
        
    public:

    void setName(string name) { //Setter
        this->Name = name;
    }

    string getName() { //Getter
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

    virtual void Work() {
        cout << Name << " is working on projects" << endl; 
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
            cout << Name << ", Fix the Bug using " << FavProgrammingLang << " language" << endl;
        }

        void Work() {
        cout << Name << " is Fixing Bugs in " << FavProgrammingLang << endl; 
    }
};

class Teacher:public Employee {

    public:
        string Subject;

        void PrepareLesson() {
            cout << Name << " is prepareing " << Subject << " lesson" << endl;
        }
        
        Teacher(string name, string company, int age, string subject)
            :Employee(name, company, age)
        {
            this->Subject = subject;
        }

        void Work() {
        cout << Name << " teaches " << Subject << endl; 
    }
};

int main() {
    Employee employee1 = Employee("Aditya", "Self Study", 22);
    employee1.Introduction();

    Employee employee2 = Employee("Rishi", "Hostel", 21);
    employee2.Introduction();

    employee1.setAge(26);

    cout << employee1.getName() << " is " << employee1.getAge() << " years old now ";

    employee1.AskForPromotion();
    employee2.AskForPromotion();

    Developer dev = Developer("Aditya", "Self-Study", 22, "C++");

    dev.FixBug();
    dev.AskForPromotion();

    Teacher tech = Teacher("Rishi", "UIT", 22, "IOT");
    tech.PrepareLesson();
    tech.AskForPromotion();

    employee1.Work();
    dev.Work();
    tech.Work();

    Employee* e1 = &dev;
    Employee* e2 = &tech;

    e1->Work();
    e2->Work();
}