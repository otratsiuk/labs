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
    void fillSecondComponents(){
        Bo.erase(Bo.begin() + q, Bo.end());
        std::cout<<"\n";
        for (int i = q; i < 2 * q; i++){
            Bo.push_back((static_cast<int>(Bo[i - r]) + static_cast<int>(Bo[i - q])) % 2);
        }

        for(auto b : Bo){
            std::cout << b << " ";
        }
    }

    uint fromBinToDec(){
        uint base = 1;
        uint dec = 0;

        for(auto i = Bo.rbegin(); i != Bo.rend(); ++i)
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

        std::uniform_int_distribution<int> distq(1, 30);
        q = distq(engine);

        std::uniform_int_distribution<int> distr(1, q);
        r = distr(engine);

        M = pow(2, q);

        std::uniform_int_distribution<int> distb(0, 1);

        std::cout<<"\nM = " << M <<"\n";
        for (int i = 0; i < q; i++)
        {
            Bo.push_back(distb(engine));
            std::cout<<Bo[i]<<" ";
        }
    }

    std::vector<float> random(int n){
        fillSecondComponents();

        uint x = fromBinToDec();
        X.push_back(static_cast<float>(x)/M);
        std::cout<<"\n"<< x << "\n";
        std::cout<<X[0]<<"\n";

        return X;
    }




};