#include "Functionalaties.h"

void CreateObjects(container &data)
{
    data.emplace_back(
        std::make_unique<Datamodular>(
            std::make_unique<Employee>(
                "sagar",
                Employtype::REGULAR,
                500000.00f

                ),

            std::vector<float>{10.0, 20.0, 30.0, 40.0}));
    data.emplace_back(

        std::make_unique<Datamodular>(
            std::make_unique<BusinessOwner>(
                200000.00f,
                300000.00f,
                "KPIT",
                BusinessType::MNC),
            std::vector<float>{10.0, 20.0, 30.0, 40.0}));
}

/*

this function will acepts a container of datamodeller pointer for rach pointer,
perform the following

a] capture the instance refrence
b]use hold_alternative to verify which type of pointer is present in the _instance
c]if pointer is of type businessowner
      i] use std::get to fetch Businessowertype (this will be safe because if has )

      2]use the fetched pointer in businesstype in businessowner to calculate tac for business

      else when pointer is of type employee:
      1. use std::get to fetch employeepointer
      2. use the fetched pointer to fetch type of employee
      3.if type is regulr tax is 10% it should 20% salary
*/
void Paytax(const container &data)
{
    for (const pointr &ptr : data)
    {
        const Vtype &val = ptr->instance();

        if (std::holds_alternative<BusinessOwnerType>(val))
        {
            const BusinessOwnerType &p = std::get<BusinessOwnerType>(val);
            std::cout <<"Business: "<< 0.1f * (p->revenue() - p->expenses());
        }
        else
        {
            const EmployeeType &p = std::get<EmployeeType>(val);
            if (p->type() == Employtype::REGULAR)
            {
                std::cout << "Employee: " << 0.1f * p->salary() << "\n";
            }
            else
            {
                std::cout << "Employee: " << 0.2f * p->salary() << "\n";
            }
        }
    }
}
/*
call parent operator overload
*/

void CalParentOperator(const container &data)
{

    if(data.empty()){
        throw std::runtime_error("Data Empty\n");
    }
            for(const  pointr &ptr:data){
                ptr->operator()();
            }
}
