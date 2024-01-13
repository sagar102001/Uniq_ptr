#ifndef DATAMODULAR_H
#define DATAMODULAR_H
#include<variant>
#include"BusinessOwner.h"
#include"Employee.h"
#include<memory>
#include<vector>
#include<iostream>

using BusinessOwnerType=std::unique_ptr<BusinessOwner>;
using EmployeeType=std::unique_ptr<Employee>;

using Vtype=std::variant<BusinessOwnerType,EmployeeType>;

class Datamodular
{
private:
     Vtype _instance;
    const std::vector<float>_goodsPrices;


public:
    void operator()();
    Datamodular( Vtype type,const std::vector<float>&price);
     Datamodular(const Datamodular &) = delete;
    Datamodular(Datamodular &&) = delete;
    Datamodular operator=(Datamodular &&) = delete;

    ~Datamodular()=default;

   const Vtype& instance() const { return _instance; }

    std::vector<float>goodsPrices() const { return _goodsPrices; }

    friend std::ostream &operator<<(std::ostream &os, const Datamodular &rhs);
};

 
 


#endif // DATAMODULAR_H
