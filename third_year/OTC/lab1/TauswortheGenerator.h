#pragma once 

#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include <cmath>

class Tausworthe{
private:
    int r, q;
    uint M; 
    std::vector<bool> Bo;
    std::vector<float> X;

private:
    void fillFirstComponents()
    {
        unsigned seed {static_cast<unsigned> (std::chrono::system_clock::now().time_since_epoch().count())};
        std::default_random_engine engine(seed);
        std::uniform_int_distribution<int> distb(0, 1);

        for (auto i = Bo.begin(); i != Bo.begin() + q; i++)
        {
            *i = distb(engine);
        }
    }

    void fillSecondComponents(){
        Bo.erase(Bo.begin() + q, Bo.end());

        for (int i = q; i < 2 * q; i++){
            Bo.push_back((static_cast<int>(Bo[i - r]) + static_cast<int>(Bo[i - q])) % 2);
        }
    }

    uint fromBinToDec(){
        uint base = 1;
        uint dec = 0;

        for(auto i = Bo.rbegin(); i != Bo.rend() - q; ++i)
        {
            dec += *i * base;
            base = base * 2; 
        }

        return dec;
    }


public:
    Tausworthe()
    {
        unsigned seed {static_cast<unsigned> (std::chrono::system_clock::now().time_since_epoch().count())};
        std::default_random_engine engine(seed);

        std::uniform_int_distribution<int> distq(1, 31);
        q = distq(engine);

        std::uniform_int_distribution<int> distr(1, q);
        r = distr(engine);

        M = pow(2, q);

        std::uniform_int_distribution<int> distb(0, 1);

        for (int i = 0; i < q; i++)
        {
            Bo.push_back(distb(engine));
        }
    }

    std::vector<float> random(int n){

        uint x;
        for(int i = 0; i < n; i++)
        {
            fillSecondComponents();
            x = fromBinToDec();
            X.push_back(static_cast<float>(x)/M);
            fillFirstComponents();
        }
        return X;
    }
};