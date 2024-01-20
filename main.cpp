#include <iostream>
#include "src/Timer.h"

void print_hello() {
    std::cout << "Hello!\n";
}

int main() {
    Timer::start_timer(1500, print_hello);

    auto timer_id = Timer::start_timer(3000, [] {
        std::cout << "I will not be printed out :(\n";
    });

    std::cout << "Timers count: " << Timer::timers_count() << std::endl;
    Timer::stop_timer(timer_id);

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "Timers count: " << Timer::timers_count() << std::endl;

    while (true);

    return 0;
}
