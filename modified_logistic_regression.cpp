#include <chrono>
#include <cmath>
#include <iostream>

#include "mlx/mlx.h"
#include "timer.h"

/**
 * An example of logistic regression with MLX.
 */
using namespace mlx::core;

int main() {
    int num_features = 100;
    int num_examples = 1'000;
    int num_iters = 10'000;
    float learning_rate = 0.1;

    // True parameters
    auto w_star = random::normal({ num_features });

    // The input examples
    auto X = random::normal({ num_examples, num_features });

    // Labels
    auto y = matmul(X, w_star) > 0;

    // Initialize random parameters
    array w = 1e-2 * random::normal({ num_features });

    auto loss_fn = [&](array w) {
        auto logits = matmul(X, w);
        auto scale = (1.0f / num_examples);
        return scale * sum(logaddexp(array(0.0f), logits) - y * logits);
    };

    auto grad_fn = grad(loss_fn);

    auto tic = std::chrono::steady_clock::now();
    for (int it = 0; it < num_iters; ++it) {
        auto grad = grad_fn(w);
        w = w - learning_rate * grad;
        eval(w);
    }
    auto toc = std::chrono::steady_clock::now();

    auto loss = loss_fn(w);
    auto acc = sum((matmul(X, w) > 0) == y) / num_examples;
    auto throughput = num_iters / (std::chrono::duration_cast<std::chrono::seconds>(toc - tic).count());
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count();
    // Getting current date and time
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);

    std::cout <<"Loss " << loss << ", Accuracy " << acc
        << ", Throughput " << throughput << " (it/s), Elapsed Time:"<<elapsed_time << "ms" << std::endl;
}

