#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

class Employee {
private:
    char* name;
    int eid;
    int age;
    double salary;
    static int count_of_employees;

    void validateAge(int age) {
        if (age < 18 || age > 60) throw invalid_argument("Age must be between 18 and 60");
    }

    void validateName(const char* name) {
        if (name == nullptr || strlen(name) == 0) throw invalid_argument("Name cannot be empty");
    }

    void validateSalary(double salary) {
        if (salary < 0) throw invalid_argument("Salary cannot be negative");
    }

public:
    Employee(const char* name, int eid, int age, double salary) : eid(eid), age(age), salary(salary) {
        validateName(name);
        validateAge(age);
        validateSalary(salary);
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        count_of_employees++;
    }

    Employee(const Employee& other) : eid(other.eid), age(other.age), salary(other.salary) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        count_of_employees++;
    }

    ~Employee() {
        delete[] name;
        count_of_employees--;
    }

    void display() const {
        cout << "Name: " << name << "\nEID: " << eid << "\nAge: " << age << "\nSalary: " << salary << endl;
    }

    Employee operator+(const Employee& other) const {
        double combinedSalary = salary + other.salary;
        return Employee("Combined", 0, 30, combinedSalary);
    }

    static int get_count_of_Employees() {
        return count_of_employees;
    }

    void updateSalary(double newSalary) {
        validateSalary(newSalary);
        salary = newSalary;
    }
};

int Employee::count_of_employees = 0;

int main() {
    Employee e1("Alice", 1, 25, 50000.0);
    Employee e2("Bob", 2, 30, 60000.0);

    cout << "Employees after creation: " << Employee::get_count_of_Employees() << endl;

    Employee e3 = e1 + e2;
    e3.display();

    Employee e4 = e1;
    cout << "Employees after copy: " << Employee::get_count_of_Employees() << endl;

    e1.updateSalary(55000.0);
    e1.display();

    // Test invalid cases
    try {
        Employee invalidName("", 3, 25, 30000.0);
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        Employee invalidAge("Charlie", 4, 17, 40000.0);
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        Employee invalidSalary("Dave", 5, 25, -1000.0);
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Final employee count: " << Employee::get_count_of_Employees() << endl;

    return 0;
}