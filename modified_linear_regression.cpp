#include <chrono>
#include <cmath>
#include <iostream>

#include "mlx/mlx.h"
#include "timer.h"

/**
 * An example of linear regression with MLX.
 */
using namespace mlx::core;

int main() {
    int num_features = 100;
    int num_examples = 1'000;
    int num_iters = 10'000;
    float learning_rate = 0.01;

    // True parameters
    auto w_star = random::normal({ num_features });

    // The input examples (design matrix)
    auto X = random::normal({ num_examples, num_features });

    // Noisy labels
    auto eps = 1e-2 * random::normal({ num_examples });
    auto y = matmul(X, w_star) + eps;

    // Initialize random parameters
    array w = 1e-2 * random::normal({ num_features });

    auto loss_fn = [&](array w) {
        auto yhat = matmul(X, w);
        return (0.5f / num_examples) * sum(square(yhat - y));
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
    auto error_norm = std::sqrt(sum(square(w - w_star)).item<float>());
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count();
    auto throughput = num_iters / (elapsed_time / 1000.0f);
    std::cout << "Loss " << loss << ", |w - w*| = " << error_norm
        << ", Throughput " << throughput << " (it/s), Elapsed Time: " << elapsed_time << "ms" << std::endl;
}

