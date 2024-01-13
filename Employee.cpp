#include "Employee.h"
std::ostream &operator<<(std::ostream &os, const Employee &rhs)
{
    os << "_Name: " << rhs._Name
       << " _type: " << static_cast<int>(rhs._type)
       << " _Salary: " << rhs._Salary;
    return os;
}
Employee::Employee(std::string name, Employtype type, float salary)
    : _Name(name), _type(type), _Salary(salary)
{
}
