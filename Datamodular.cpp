#include "Datamodular.h"

void Datamodular::operator()()
{
    if (_goodsPrices.empty())
    {
        throw std::runtime_error("Not Found\n");
    }
    float total = 0.0f;

    for (float val : _goodsPrices)
    {
        total += val;
    }
    std::cout << "\nAverage of the goods is: " << total / _goodsPrices.size() << "\n";
}

Datamodular::Datamodular(Vtype type, const std::vector<float> &price)
    : _instance(std::move(type)), _goodsPrices(price)
{
}

std::ostream &operator<<(std::ostream &os, const Datamodular &rhs)
{
    os << "_instance: ";
    std::visit(
        [&](auto &&p)
        { os << *p; },

        rhs._instance);

    os << " _goodsPrices: ";

    for (float val : rhs._goodsPrices)
    {
        os << val << "\n";
    }
    return os;
}
