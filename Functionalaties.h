#ifndef FUNCTIONALATIES_H
#define FUNCTIONALATIES_H
#include <iostream>
#include "Employee.h"
#include "BusinessOwner.h"
#include <memory>
#include "Datamodular.h"
#include <vector>

using pointr=std::unique_ptr<Datamodular>;
using container=std::vector<pointr>;

void CreateObjects(container &data);

void Paytax(const container &data);

void CalParentOperator(const container &data);

#endif // FUNCTIONALATIES_H
