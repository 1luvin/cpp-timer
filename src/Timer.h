#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H

#include <thread>
#include <vector>

class Timer {
public:

    Timer() = delete;

    static std::thread::id start_timer(const uint64_t &duration, void (*function)());

    static void stop_timer(const std::thread::id &timer_id);

    static size_t timers_count();

private:
    static std::vector<std::thread *> timers;

    static void dispose_timer(const std::thread::id &timer_id, const bool &need_stop);
};

#endif //TIMER_TIMER_H
