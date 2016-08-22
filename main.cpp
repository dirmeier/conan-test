#include <vector>
#include <iostream>
#include "mvrnorm.hpp"

int main()
{
    Eigen::Vector2d mean;
    Eigen::Matrix2d covar;
    mean << -1,0.5; // Set the mean
    // Create a covariance matrix
    // Much wider than it is tall
    // and rotated clockwise by a bit
    covar = genCovar(3,0.1,M_PI/5.0);

    // Create a bivariate gaussian distribution of doubles.
    // with our chosen mean and covariance
    Eigen::EigenMultivariateNormal<double,2> normX(mean,covar);

    return 0;
