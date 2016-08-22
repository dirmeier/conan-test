#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "mvrnorm.hpp"

int main()
{
    std::cout<<"Ten samples of a multivariate Gaussian:"<<std::endl;

    Eigen::Matrix<float, 3, 1> m;
    m << 0, 0, 0;
    Eigen::Matrix<float, 3, 3> cov;
    cov << 1, 0, 0,
        0, 1, 0,
        0, 0, 1;

    cstat::mvrnorm<float> s(m, cov);
    std::vector<float> vec = s.sample();
    for (int ii = 0; ii < 10; ++ii) 
    {
        for (uint32_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << "\n";
    }
    return 0;
}