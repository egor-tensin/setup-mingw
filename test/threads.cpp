#include <array>
#include <cstddef>
#include <exception>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

namespace {

struct Counter {
    std::mutex mtx;
    std::size_t impl = 0;
};

void do_something(Counter& counter) {
    std::lock_guard<std::mutex> lck{counter.mtx};
    ++counter.impl;
    std::cout << "Doing something #" << counter.impl << '\n';
}

}

int main() {
    try {
        Counter counter;
        std::array<std::thread, 3> workers;
        for (auto& worker : workers) {
            worker = std::thread{&do_something, std::ref(counter)};
        }
        for (auto& worker : workers) {
            worker.join();
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}
