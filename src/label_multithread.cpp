#include <algorithm>
#include <atomic>
#include <mutex>
#include <queue>
#include <thread>
#include "utils.h"
#include "constants.h"

unsigned long long labelOptimallyMultiThread(const Tree &tree, Labeling &labeling) {
    // Entrypoint for the algorithm.

    // Finds any possible root for the tree.
    auto root = tree.findARoot(labeling);

    // initializes the total cost as zero
    std::atomic_ullong total_cost = 0;

    // Creates job queue
    std::mutex queue_mutex;
    std::queue<char> job_queue;
    std::for_each(kAlphabet, kAlphabet + kNLetters, [&](char l) {
        job_queue.push(l);
    });

    // Defines worker function
    auto worker = [&]() {
        char letter;
        for (;;) {
            {
                std::lock_guard<std::mutex> lock(queue_mutex);  
                if (job_queue.empty())
                        break;
                letter = job_queue.front();
                job_queue.pop();
            }

            total_cost += labelOneLetter(tree, labeling, root, root, letter);
        }
    };

    // initializing threads
    std::array<std::thread, kNumThreads> threads;
    for (auto &thread : threads)
        thread = std::thread(worker);

    for (auto &thread : threads)
        thread.join();

    // returns the total cost of the run
    return total_cost;
}