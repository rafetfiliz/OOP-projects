//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Rafet FİLİZ
//---Student Number: 150200028
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "utils.h"

StatisticalDistribution* choose_function(int type){
    if(type == 0){
        NormalDistribution* normal = new NormalDistribution;
        return normal;
    }

    else if(type == 1){
        UniformDistribution* uniform = new UniformDistribution;
        return uniform;
    }

     else if(type == 2){
        ExponentialDistribution* exp = new ExponentialDistribution;
        return exp;
    }

    else{
       throw "Unidentified distribution function!";
    }
}

double many_trials(StatisticalDistribution* distribution, std::vector<double> rand_sample, double t, int trials, int size, int seed){
    double precision = 0.0;
    double success = 0.0;

    for(int i = 0; i < trials; i++){
        std::vector<double> rand = distribution->sample(size, seed);
        std::vector<double> vec = distribution->calculate_confidence_interval(rand, size, t); // Vector holds confidence interval
        if(distribution->getMean() > vec.at(0) && vec.at(2) > distribution->getMean())
            success += 1;
        seed+=1;  
    }

    precision = success / trials;
    return precision;
}