#ifndef CSTAT_MVRNORM__HPP
#define CSTAT_MVRNORM__HPP

#include <vector>
#include <cmath>
#include <random>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

namespace cstat
{
    namespace internal
    {
        template<typename T>
        struct rnrorm
        {
            static std::mt19937 rng_;
            mutable std::normal_distribution<T> norm_;

            template<typename U>
            inline T operator()(U, U = 0) const
            {
                return norm_(rng_);
            }

            inline void seed(const uint64_t &s) const
            {
                rng_.seed(s);
            }
        };

        template<typename T>
        std::mt19937 rnrorm<T>::rng_;
    }

    template<typename T>
    class mvrnorm
    {

    public:
        mvrnorm(const Eigen::Matrix<T, Eigen::Dynamic, 1> &mean,
                const Eigen::Matrix <T, Eigen::Dynamic, Eigen::Dynamic> &cov)
            :mean_(mean), cov_(cov), LEN_(static_cast<unsigned int>(mean.rows()))
        {
            gen_.seed(23);
            Eigen::SelfAdjointEigenSolver < Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> > slv(cov);
            transform_ = slv.eigenvectors() *
                slv.eigenvalues().cwiseMax(0).cwiseSqrt().asDiagonal();
        }

        std::vector<T> sample()
        {
            std::vector<T> vec(LEN_);
            for (unsigned int i = 0; i < LEN_; ++i)
                vec[i] = gen_();

        }

    private:
        Eigen::Matrix <T, Eigen::Dynamic, Eigen::Dynamic> cov_;
        Eigen::Matrix <T, Eigen::Dynamic, Eigen::Dynamic> transform_;
        const Eigen::Matrix<T, Eigen::Dynamic, 1> mean_;
        const unsigned int LEN_;
        internal::rnrorm<T> gen_;
    };

}
#endif // MVRNORM__HPP