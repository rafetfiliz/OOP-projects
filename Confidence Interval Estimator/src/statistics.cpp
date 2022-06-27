//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Rafet FİLİZ
//---Student Number: 150200028
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "statistics.h"
#include <random>
#include <iostream>

const double StatisticalDistribution::getMean(){
    return this->mean;
}

std::vector<double> StatisticalDistribution::calculate_confidence_interval(std::vector<double> vec, int size, double t){
    double X = 0; //sample mean
    double S = 0; //sample standard deviation
    double sum = 0;
    double temp = 0;
    double lower_bound = 0;
    double upper_bound = 0;
    std::vector<double> newVector;

    for (auto i = vec.begin(); i != vec.end(); ++i)
        sum += *i;    
    X = sum / size;
    
    for (auto i = vec.begin(); i != vec.end(); ++i)
        temp += pow((*i - X), 2);
    temp = temp / (size - 1);
    S = sqrt(temp);

    lower_bound = X - (t * (S / sqrt(size)));
    upper_bound = X + (t * (S / sqrt(size)));

    newVector.push_back(lower_bound);
    newVector.push_back(X);
    newVector.push_back(upper_bound);

    return newVector;
}

NormalDistribution::NormalDistribution(){
    this->mean = 0.0;
    this->stddev = 1.0;
}

std::vector<double> NormalDistribution::sample(int size, int seed){ 
    std::vector<double> newVector;
    std::default_random_engine generator;
    generator.seed(seed);
    std::normal_distribution<double> distribution(mean, stddev);
    
    for(int i = 0; i < size; i++){      
        double number = distribution(generator);
        newVector.push_back(number);
    }

    return newVector;
}


UniformDistribution::UniformDistribution(){
    this->mean = 0.0;
    this->a = -1.0;
    this->b = 1.0;
}


std::vector<double> UniformDistribution::sample(int size, int seed){
    std::vector<double> newVector;
    std::default_random_engine generator;
    generator.seed(seed);
    std::uniform_real_distribution<double> distribution(a, b);
    
    for(int i = 0; i < size; i++){
        double number = distribution(generator);
        newVector.push_back(number);
    }

    return newVector;
}


ExponentialDistribution::ExponentialDistribution(){
    this->mean = 1.0;
    this->lambda = 1.0;
}


std::vector<double> ExponentialDistribution::sample(int size, int seed){
    std::vector<double> newVector;
    std::default_random_engine generator ;
    generator.seed(seed);
    std::exponential_distribution<double> distribution(lambda);

    for(int i = 0; i < size; i++){
        double number = distribution(generator);
        newVector.push_back(number);
    }

    return newVector;
}