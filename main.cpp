#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "mvrnorm.hpp"

int main()
{
     std::cout<<"Hello, World!"<<std::endl;
    Eigen::Matrix<float, 3, 1> m;
    m << 1, 2, 3;
    Eigen::Matrix<float, 3, 3> cov;
    cov << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;
    cstat::mvrnorm<float> s(m, cov);
    std::vector<float> vec = s.sample();
    for (unsigned int i = 0; i < vec.size();++i)
        std::cout << vec[i] << "\n";
    return 0;
}