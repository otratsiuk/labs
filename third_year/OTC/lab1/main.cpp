#include "TauswortheGenerator.h"
#include <iomanip>

int main()
{
    Tausworthe generator100;
    Tausworthe generator500;
    Tausworthe generator1000;
    Tausworthe generator10000;
    Tausworthe generator30000;
    
    auto vector100   = generator100.random(100);
    auto vector500   = generator500.random(500);
    auto vector1000  = generator1000.random(1000);
    auto vector10000 = generator10000.random(10000);
    auto vector30000 = generator30000.random(30000); 

    std::cout<<std::left
             <<std::setw(15)<<"100"
             <<std::setw(15)<<"500"
             <<std::setw(15)<<"1000"
             <<std::setw(15)<<"10000"
             <<std::setw(15)<<"30000\n";
    
    for(int i = 0; i < 50; i++){
        std::cout<<"\n"
                 <<std::left
                 <<std::setw(15)<<vector100[i]
                 <<std::setw(15)<<vector500[i]
                 <<std::setw(15)<<vector1000[i]
                 <<std::setw(15)<<vector10000[i]
                 <<std::setw(15)<<vector30000[i];
    }



    return 0;
}