/**
 * Author: Simon Dirmeier
 * Date: 23/08/16
 * Email: simon.dirmeier@bsse.ethz.ch
 */

#ifndef CSTAT_MVRNORM_HPP
#define CSTAT_MVRNORM_HPP

#include <vector>
#include <cmath>
#include <random>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

namespace cstat
{                

template<typename T>
 class rnorm
        {

        public:
            rnorm(const unsigned long seed): rng_(seed), norm_()
            {}

            T operator()()
            {
                return norm_(rng_);
            }

        private:
            std::mt19937 rng_;
            std::normal_distribution<T> norm_;
        };

    template<typename T>
    class mvrnorm
    {

    public:
        mvrnorm(const Eigen::Matrix<T, Eigen::Dynamic, 1> &mean,
                const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> &cov)
            : LEN_(static_cast<uint32_t>(mean.rows())),mean_(mean),cov_(cov), ran_(23)
        {
            Eigen::SelfAdjointEigenSolver
            <Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> > slv(cov);
            transform_ = slv.eigenvectors() *
                         slv.eigenvalues()
                            .cwiseMax(0).cwiseSqrt()
                            .asDiagonal();
        }

        std::vector<T> sample()
        {
            Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> vec(LEN_, 1);
            for (uint32_t i = 0; i < LEN_; ++i)
                vec(i, 0) = ran_();
            vec = mean_ + transform_ * vec;
            std::vector<T> ret(LEN_);
            for (uint32_t i = 0; i < LEN_; ++i)
                ret[i] = vec(i, 0);            
            return ret;
        }

    private:
        const uint32_t LEN_;
        const Eigen::Matrix<T, Eigen::Dynamic, 1> mean_;        
        Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> cov_;
        Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> transform_;    
        rnorm<T> ran_;       

    };

}
#endif // CSTAT_MVRNORM_HPP