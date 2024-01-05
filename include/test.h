
#ifndef SCANCODE_TEST_H
#define SCANCODE_TEST_H

#include "column.h"
#include "types.h"
#include "configure.h"
#include "queryqueue.h"
#include "hybrid_timer.h"
#include "test.h"
#include "cabin.h"

template<class Algorithm>
bool AlgoScan(arg_t arg, HybridTimer &t1, WordUnit x, Algorithm* algo){
    t1.Start();
    for (size_t r = 0; r < arg.repeat; r++) {
        algo->Scan(x, x, op_le);
    }
    t1.Stop();

    bool result = algo->CheckResult(x, x, op_le);
    return result;
}

template<class Algorithm>
void Test(Column* column, QueryQueue* query, arg_t arg){
    WordUnit x = query->QueryLook(0);
#ifdef PRINT_AUXILIARY_INFO
    std::cout << "select value: " << x << std::endl;
#endif
    std::cout << "selectivity: " << arg.selectivity << "%" << std::endl;
    std::cout << "predicate value: " << x << std::endl;

    HybridTimer t1{};

    auto algo = new Algorithm(column, query);
    std::cout << "[INFO ] Creating index ..." << std::endl;
    algo->CreateIndex();

    std::cout << "[INFO ] Executing scan ..." << std::endl;
    bool result = AlgoScan<Algorithm>(arg, t1, x, algo);

    std::cout << "[INFO ] Accuracy showing..." << std::endl;
    std::cout << "accuracy: " << (result ? "right" : "wrong")  << std::endl;
    std::cout << "Wall time (msec): ";
    std::cout << t1.GetSeconds()*1000 / arg.repeat << std::endl;

    std::cout << "[INFO ] Releasing memory ..." << std::endl;
    algo->Destroy();
}

//varied in selectivity
template<class Algorithm>
void TestPatch(Column* column, QueryQueue* query, arg_t arg){
    auto algo = new Algorithm(column, query);

    std::cout << "[INFO ] Creating index ..." << std::endl;
    algo->CreateIndex();

    std::cout << "[INFO ] Executing scan ..." << std::endl;
    double result[arg.patch_num+1];
    size_t correctness = 0;
    for(size_t i = 0; i < arg.patch_num+1; i++)
    {
        WordUnit x = query->QueryLook(i);
        HybridTimer t1{};

        if(true == AlgoScan<Algorithm>(arg, t1, x, algo)) {
            correctness++;
        }
        result[i] = t1.GetSeconds() / arg.repeat;
    }

    std::cout << "[INFO ] Accuracy showing..." << std::endl;
    std::cout << "accuracy: " << correctness << " / " << arg.patch_num+1 << std::endl;

    std::cout << "[INFO ] Writing file" << std::endl;
    std::ofstream outfile;
    std::string file;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::string time = std::to_string(1 + ltm->tm_mon) + "-" + std::to_string(ltm->tm_mday) + " hour " +
            std::to_string(ltm->tm_hour) + " min " + std::to_string(ltm->tm_min) + " second " + std::to_string(ltm->tm_sec);
    file = "../data/result/"+ std::to_string(8*sizeof(WordUnit)) + "_result_" + algo->name +"_"+ std::to_string(arg.size) +" "+ time;
    outfile.open(file);
    for(double i : result)
    {
        outfile << i << std::endl;
    }
    outfile.close();

    std::cout << "[INFO ] Releasing memory ..." << std::endl;
    algo->Destroy();
}

//varied in query distribution
template<class Algorithm>
void TestQuery(Column* column, QueryQueue* query, arg_t arg){
    auto algo = new Algorithm(column, query);

    std::cout << "[INFO ] Creating index ..." << std::endl;
    algo->CreateIndex();

    std::cout << "[INFO ] Executing scan ..." << std::endl;
    size_t queryNumber = query->query.size();
    double result[queryNumber];
    size_t correctness = 0;
    double sumTime = 0;

    HybridTimer t1{};
    t1.Start();
    for(size_t i = 0; i < queryNumber; i++)
    {
        WordUnit x = query->QueryLook(i);

        algo->Scan(x, x, op_le);
        // bool single_result = algo->CheckResult(x, x, op_le);
        // if(single_result) {
        //     correctness++;
        // }
    }

    t1.Stop();
    sumTime = t1.GetSeconds();

    // std::cout << "[INFO ] Accuracy showing..." << std::endl;
    // std::cout << "accuracy: " << correctness << " / " << queryNumber << std::endl;
    std::cout << "total time (sec): " << sumTime << std::endl;

    std::cout << "[INFO ] Releasing memory ..." << std::endl;
    algo->Destroy();
}

void TestQuerySPA(Column* column, QueryQueue* query, workloadFeature* wf, arg_t arg){
    auto algo = new Cabin(column, query, wf);

    std::cout << "[INFO ] Creating index ..." << std::endl;
    algo->CreateIndex();

    std::cout << "[INFO ] Executing scan ..." << std::endl;
    size_t queryNumber = query->query.size();
    double result[queryNumber];
    size_t correctness = 0;
    double sumTime = 0;

    HybridTimer t1{};
    t1.Start();
    for(size_t i = 0; i < queryNumber; i++)
    {
        WordUnit x = query->QueryLook(i);
        algo->Scan(x, x, op_le);
        // bool single_result = algo->CheckResult(x, x, op_le);
        // if(single_result) {
        //     correctness++;
        // }
    }
    t1.Stop();
    sumTime = t1.GetSeconds();
    // std::cout << "[INFO ] Accuracy showing..." << std::endl;
    // std::cout << "accuracy: " << correctness << " / " << queryNumber << std::endl;
    std::cout << "total time (sec): " << sumTime << std::endl;

    std::cout << "[INFO ] Releasing memory ..." << std::endl;
    algo->Destroy();
}

// Zipf distribution
template<class IntType = unsigned long, class RealType = double>
class zipf_distribution
{
public:
    typedef IntType result_type;

    static_assert(std::numeric_limits<IntType>::is_integer, "");
    static_assert(!std::numeric_limits<RealType>::is_integer, "");

    /// zipf_distribution(N, s, q)
    /// Zipf distribution for `N` items, in the range `[1,N]` inclusive.
    /// The distribution follows the power-law 1/(n+q)^s with exponent
    /// `s` and Hurwicz q-deformation `q`.
    zipf_distribution(const IntType n=std::numeric_limits<IntType>::max(),
                      const RealType s=1.0,
                      const RealType q=0.0)
            : n(n)
            , _s(s)
            , _q(q)
            , oms(1.0-s)
            , spole(abs(oms) < epsilon)
            , rvs(spole ? 0.0 : 1.0/oms)
            , H_x1(H(1.5) - h(1.0))
            , H_n(H(n + 0.5))
            , cut(1.0 - H_inv(H(1.5) - h(1.0)))
            , dist(H_x1, H_n)
    {
        if (-0.5 >= q)
            throw std::runtime_error("Range error: Parameter q must be greater than -0.5!");
    }
    void reset() {}

    IntType operator()(std::mt19937& rng)
    {
        while (true)
        {
            const RealType u = dist(rng);
            const RealType x = H_inv(u);
            const IntType  k = std::round(x);
            if (k - x <= cut) return k;
            if (u >= H(k + 0.5) - h(k))
                return k;
        }
    }

    /// Returns the parameter the distribution was constructed with.
    RealType s() const { return _s; }
    /// Returns the Hurwicz q-deformation parameter.
    RealType q() const { return _q; }
    /// Returns the minimum value potentially generated by the distribution.
    result_type min() const { return 1; }
    /// Returns the maximum value potentially generated by the distribution.
    result_type max() const { return n; }


private:
    IntType    n;     ///< Number of elements
    RealType   _s;    ///< Exponent
    RealType   _q;    ///< Deformation
    RealType   oms;   ///< 1-s
    bool       spole; ///< true if s near 1.0
    RealType   rvs;   ///< 1/(1-s)
    RealType   H_x1;  ///< H(x_1)
    RealType   H_n;   ///< H(n)
    RealType   cut;   ///< rejection cut
    std::uniform_real_distribution<RealType> dist;  ///< [H(x_1), H(n)]

    // This provides 16 decimal places of precision,
    // i.e. good to (epsilon)^4 / 24 per expanions log, exp below.
    static constexpr RealType epsilon = 2e-5;

    /** (exp(x) - 1) / x */
    static double
    expxm1bx(const double x)
    {
        if (std::abs(x) > epsilon)
            return std::expm1(x) / x;
        return (1.0 + x/2.0 * (1.0 + x/3.0 * (1.0 + x/4.0)));
    }

    /** log(1 + x) / x */
    static RealType
    log1pxbx(const RealType x)
    {
        if (std::abs(x) > epsilon)
            return std::log1p(x) / x;
        return 1.0 - x * ((1/2.0) - x * ((1/3.0) - x * (1/4.0)));
    }
    /**
     * The hat function h(x) = 1/(x+q)^s
     */
    const RealType h(const RealType x)
    {
        return std::pow(x + _q, -_s);
    }

    /**
     * H(x) is an integral of h(x).
     *     H(x) = [(x+q)^(1-s) - (1+q)^(1-s)] / (1-s)
     * and if s==1 then
     *     H(x) = log(x+q) - log(1+q)
     *
     * Note that the numerator is one less than in the paper
     * order to work with all s. Unfortunately, the naive
     * implementation of the above hits numerical underflow
     * when q is larger than 10 or so, so we split into
     * different regimes.
     *
     * When q != 0, we shift back to what the paper defined:

     *    H(x) = (x+q)^{1-s} / (1-s)
     * and for q != 0 and also s==1, use
     *    H(x) = [exp{(1-s) log(x+q)} - 1] / (1-s)
     */
    const RealType H(const RealType x)
    {
        if (not spole)
            return std::pow(x + _q, oms) / oms;

        const RealType log_xpq = std::log(x + _q);
        return log_xpq * expxm1bx(oms * log_xpq);
    }

    /**
     * The inverse function of H(x).
     *    H^{-1}(y) = [(1-s)y + (1+q)^{1-s}]^{1/(1-s)} - q
     * Same convergence issues as above; two regimes.
     *
     * For s far away from 1.0 use the paper version
     *    H^{-1}(y) = -q + (y(1-s))^{1/(1-s)}
     */
    const RealType H_inv(const RealType y)
    {
        if (not spole)
            return std::pow(y * oms, rvs) - _q;

        return std::exp(y * log1pxbx(oms * y)) - _q;
    }
};

#endif //SCANCODE_TEST_H
