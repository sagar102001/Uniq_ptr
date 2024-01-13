#include <iostream>
#include "Functionalaties.h"
#include <thread>
#include <array>
int main()
{

    container data;
  
     
    

    std::array<std::thread, 3> t;
    t[0] = std::thread(CreateObjects, std::ref(data));

    t[0].join();
    t[1] = std::thread(Paytax, std::ref(data));

    t[2] = std::thread(CalParentOperator, std::ref(data));

    for (std::thread &th : t)
    {
        if (th.joinable())
        {
            th.join();
        }
    }

    
}