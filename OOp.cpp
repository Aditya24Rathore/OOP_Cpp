/*
 * Object-Oriented Programming (OOP) Concepts Demonstration in C++
 * This file demonstrates the four main pillars of OOP:
 * 1. Abstraction - Abstract class with pure virtual functions
 * 2. Inheritance - Classes inheriting from base classes
 * 3. Encapsulation - Private, protected, and public access modifiers
 * 4. Polymorphism - Virtual functions and runtime polymorphism
 */

#include <bits/stdc++.h>
using namespace std;

// ABSTRACTION: Abstract class that defines a contract for promotion eligibility
// This class cannot be instantiated directly - it's purely for defining interface
class AbstractionPromotion {
    // Pure virtual function (= 0) makes this an abstract class
    // Any class inheriting from this MUST implement this function
    virtual void AskForPromotion() = 0;

};

// INHERITANCE: Employee class inherits from AbstractionPromotion
// This demonstrates "IS-A" relationship - Employee IS-A Promotable entity
class Employee : AbstractionPromotion {

    // ENCAPSULATION: Access modifiers control visibility of class members
    
    private:      
        // Private members - only accessible within this class
        // Data hiding principle - internal implementation details are hidden
        string Company;
        int Age;

    protected:
        // Protected members - accessible in this class and its derived classes
        // Allows controlled access to derived classes
        string Name;
        
    public:
        // Public members - accessible from anywhere
        // These form the public interface of the class

    // ENCAPSULATION: Setter method with data validation
    // Provides controlled access to private data members
    void setName(string name) { //Setter
        this->Name = name;
    }

    // ENCAPSULATION: Getter method to access private data
    // Provides read-only access to internal state
    string getName() { //Getter
        return Name;
    }

    // Setter with business logic/validation
    // Demonstrates data validation and business rules
    void setAge(int age) {
        // Business rule: Employee must be at least 18 years old
        if(age >= 18)
        this->Age = age;
    }

    // Getter for Age - provides read access to private member
    int getAge() {
        return Age;
    }

    // Method to display employee information
    // Demonstrates how objects can perform actions using their data
    void Introduction() {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }

    // CONSTRUCTOR: Special method to initialize object state
    // Called automatically when object is created
    Employee(string name, string company, int age) {
        this->Name = name;
        this->Company = company;
        this->Age = age;
    }

    // Implementation of pure virtual function from AbstractionPromotion
    // This makes Employee a concrete class (can be instantiated)
    void AskForPromotion() {
        // Business logic for promotion eligibility
        if(Age >= 25)
            cout <<  Name << ", got the promotion!" << endl;
        else
            cout << Name << ", Sorry! No promotion for you." << endl;

    }

    // POLYMORPHISM: Virtual function that can be overridden by derived classes
    // Enables runtime polymorphism (late binding)
    virtual void Work() {
        cout << Name << " is working on projects" << endl; 
    }
};

// INHERITANCE: Developer class inherits from Employee (IS-A relationship)
// Developer IS-A Employee with additional specialized functionality
class Developer:public Employee {

    public:
        // Additional attribute specific to Developer
        string FavProgrammingLang;

        // Constructor that calls parent class constructor
        // Demonstrates constructor chaining in inheritance
        Developer(string name, string company, int age, string favProgrammingLang)
            :Employee(name, company, age)  // Call parent constructor
        {
            this->FavProgrammingLang = favProgrammingLang;
        }

        // Specialized method for Developer class
        // Demonstrates how derived classes can have their own unique methods
        void FixBug() {
            cout << Name << ", Fix the Bug using " << FavProgrammingLang << " language" << endl;
        }

        // POLYMORPHISM: Override the virtual Work() function from Employee
        // This provides Developer-specific implementation
        void Work() {
        cout << Name << " is Fixing Bugs in " << FavProgrammingLang << endl; 
    }
};

// INHERITANCE: Teacher class - another example of IS-A relationship
// Teacher IS-A Employee with teaching-specific functionality
class Teacher:public Employee {

    public:
        // Additional attribute specific to Teacher
        string Subject;

        // Method specific to Teacher class
        void PrepareLesson() {
            cout << Name << " is prepareing " << Subject << " lesson" << endl;
        }
        
        // Constructor with parent class initialization
        Teacher(string name, string company, int age, string subject)
            :Employee(name, company, age)  // Initialize parent class
        {
            this->Subject = subject;
        }

        // POLYMORPHISM: Override Work() method for Teacher-specific behavior
        void Work() {
        cout << Name << " teaches " << Subject << endl; 
    }
};

int main() {
    // OBJECT CREATION: Creating instances of Employee class
    cout << "=== OBJECT CREATION AND ENCAPSULATION ==="<< endl;
    Employee employee1 = Employee("Aditya", "CLG", 22);
    employee1.Introduction();

    Employee employee2 = Employee("Rishi", "Hostel", 21);
    employee2.Introduction();

    // ENCAPSULATION: Using setter methods to modify private data
    cout << "\n=== USING SETTERS AND GETTERS ==="<< endl;
    employee1.setAge(26);

    cout << employee1.getName() << " is " << employee1.getAge() << " years old now " << endl;

    // ABSTRACTION: Using the implemented abstract method
    cout << "\n=== PROMOTION LOGIC (ABSTRACTION) ==="<< endl;
    employee1.AskForPromotion();
    employee2.AskForPromotion();

    // INHERITANCE: Creating objects of derived classes
    cout << "\n=== INHERITANCE DEMONSTRATION ==="<< endl;
    Developer dev = Developer("Aditya", "Self-Study", 22, "C++");

    dev.FixBug();  // Developer-specific method
    dev.AskForPromotion();  // Inherited method from Employee

    Teacher tech = Teacher("Rishi", "UIT", 22, "IOT");
    tech.PrepareLesson();  // Teacher-specific method
    tech.AskForPromotion();  // Inherited method from Employee

    // POLYMORPHISM: Method overriding - same method name, different behavior
    cout << "\n=== COMPILE-TIME POLYMORPHISM (METHOD OVERRIDING) ==="<< endl;
    employee1.Work();  // Employee's version of Work()
    dev.Work();        // Developer's overridden version
    tech.Work();       // Teacher's overridden version

    // RUNTIME POLYMORPHISM: Using base class pointers to call derived class methods
    cout << "\n=== RUNTIME POLYMORPHISM (VIRTUAL FUNCTIONS) ==="<< endl;
    Employee* e1 = &dev;   // Base class pointer pointing to derived object
    Employee* e2 = &tech;  // Base class pointer pointing to derived object

    e1->Work();  // Calls Developer::Work() due to virtual function
    e2->Work();  // Calls Teacher::Work() due to virtual function
}