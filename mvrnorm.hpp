#ifndef MVRNORM__HPP
#define MVRNORM__HPP

#include <vector>
#include <cmath>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>
#include <Dense>
#include <Eigenvalues> 

class mvrnorm
{

    boost::mt19937 rng;    // The uniform pseudo-random algorithm
    boost::normal_distribution<double> norm;  // The gaussian combinator
    boost::variate_generator<boost::mt19937&,boost::normal_distribution<double> >
       randN; // The 0-mean unit-variance normal generator

    Eigen::Matrix<double,10,10> rot;
    Eigen::Matrix<double,10,1> scl;

    Eigen::Matrix<double,10,1> mean_;

public:

    mvrnorm(std::vector<double>& mean,
    		std::vector< std::vector<double> >& cov) 
     :mean_(mean.data()), randN(rng,norm)
    {
        cov_(cov);
    }

    std::vector<double> sample() const
    {
    	// Eigen::Matrix<double, SZ , 1> ret;
     //    for (int i = 0; i < SZ ; ++i)        
     //        ret[i] = gen_();
     //    ret = sd_ * ret + mean_;
        
        std::vector<double> res(10);
        for (int i = 0; i < 10; ++i)        
            res[i] = randN();
            // res[i] = ret(i, 0);
      	return res;   
    }

private:

     /* Compute SVD
     */
    void cov_(std::vector< std::vector<double> >& cov) const
    {
        // Eigen::Matrix<double, SZ, SZ> covm;
        // for (int i = 0; i < SZ; ++i)
        //     for (int j = 0; j < SZ; ++j)
        //     covm(i, j) = cov[i][j];
        // Eigen::SelfAdjointEigenSolver< Eigen::Matrix<double, SZ, SZ > > solv(covm);
        // sd_(solv.eigenvectors());
        // Eigen::Matrix<double, SZ, 1> scl = solv.eigenvalues();
        // for (int i = 0; i < SZ; ++i) scl(i, 0) = sqrt(scl(i, 0));
        // sd_(sd_ * scl.asDiagonal());
    }

};

#endif // MVRNORM__HPP