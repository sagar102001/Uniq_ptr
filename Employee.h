#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include "EmployeeType.h"
class Employee
{
private:
    std::string _Name;
    Employtype _type;
    float _Salary;

public:
    Employee(std::string name, Employtype type, float salary);
    Employee() = delete;
    Employee(const Employee &) = delete;
    Employee(Employee &&) = delete;
    Employee operator=(Employee &&) = delete;

    ~Employee() = default;

    Employtype type() const { return _type; }

    float salary() const { return _Salary; }

    std::string name() const { return _Name; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
