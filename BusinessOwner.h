#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H
#include "BusinessType.h"
#include <iostream>
class BusinessOwner
{
private:
    float _expenses;
    float _revenue;
    std::string _registeredBusinessName;
    BusinessType _type;

public:
    BusinessOwner(float expenses, float revenue, std::string Bname, BusinessType type);
    ~BusinessOwner() = default;
    BusinessOwner(const BusinessOwner &) = delete;
    BusinessOwner(BusinessOwner &&) = delete;
    BusinessOwner operator=(BusinessOwner &&) = delete;

    float expenses() const { return _expenses; }

    float revenue() const { return _revenue; }

    std::string registeredBusinessName() const { return _registeredBusinessName; }

    void setType(const BusinessType &type) { _type = type; }

    BusinessType type() const { return _type; }

    friend std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs);
};

#endif // BUSINESSOWNER_H
