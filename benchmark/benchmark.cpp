#include <benchmark/benchmark.h>
#include "solution.h"


class FrameWorkBenchmark : public benchmark::Fixture {
public:
    void SetUp(const ::benchmark::State& state) override {
        freopen("../data/data.in", "r", stdin);
        std::cin >> dimension_;
        int pointsnum;
        std::cin >> pointsnum;
        base_.resize(dimension_ * pointsnum);
        for (int i = 0; i < dimension_ * pointsnum; i++) {
            std::cin >> base_[i];
        }
        int querynum;
        std::cin >> querynum;
        query_.resize(dimension_ * querynum);
        for (int i = 0; i < dimension_ * querynum; i++) {
            std::cin >> query_[i];
        }
        solution_.build(dimension_, base_);
        // std::cout << "SetUp" << std::endl;
        fclose(stdin);
        res_ = (int*)malloc(10 * sizeof(int));
    }

    void TearDown(const ::benchmark::State& state) override {
        // std::cout << "TearDown" << std::endl;
        free(res_);
    }

protected:
    int dimension_;
    int *res_;
    std::vector<float> base_;
    std::vector<float> query_;
    Solution solution_;
};

BENCHMARK_DEFINE_F(FrameWorkBenchmark, TestSolution)(benchmark::State& state) {
    for (auto _ : state) {
        for(int i = 0; i < query_.size(); i += dimension_) {
            // std::cout<< "in testing" << i << " dimension=" << dimension_ << "size=" << query_.size() << std::endl;
            int* res = (int*)malloc(10 * sizeof(int));
            solution_.search(std::vector<float>(query_.begin() + i, query_.begin() + i + dimension_), res_);
            benchmark::DoNotOptimize(res_);
            // std::cout<< "end testing" << i << " dimension=" << dimension_ << "size=" << query_.size() << std::endl;
            
        }
    }
}

BENCHMARK_REGISTER_F(FrameWorkBenchmark, TestSolution)->MinTime(2.0);

BENCHMARK_MAIN(); // Main function for the benchmark
