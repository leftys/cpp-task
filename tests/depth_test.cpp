#include <chrono>
#include <iostream>
#include <cassert>
#include <random>

#include "depth.hpp"

int main() {
    auto depth = std::make_unique<Depth>();
    assert(depth != nullptr);
    
    const int iterations = 100000;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> price_dist(99.0, 101.0);

    // Pre-generate random update prices before the measured loop
    std::vector<double> prices(iterations);

    for (int i = 0; i < iterations; ++i) {
        prices[i] = price_dist(gen);
    }

    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < iterations; ++i) {
        float qty = 10.0f;
        if (i % 10 == 0) {
            qty = 0.0f;
        }
        // To be implemented, eg:
        // side = static_cast<...>(i % 2);
        // price = prices[i]
        // call_some_update_price_function(...)
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    
    double total_time_ms = duration.count() / 1000.0;
    double mean_per_iteration_ns = duration.count() / static_cast<double>(iterations);
    
    std::cout << "Benchmark: " << iterations << " iterations\n";
    std::cout << "Total time: " << total_time_ms << " ms\n";
    std::cout << "Mean per iteration: " << mean_per_iteration_ns << " ns\n";
    
    return 0;
}
