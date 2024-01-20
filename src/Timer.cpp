#include "Timer.h"
#include <algorithm>

std::vector<std::thread *> Timer::timers;

std::thread::id Timer::start_timer(const uint64_t &duration, void (*function)()) {
    auto timer = new std::thread(
            [duration, function](void (*dispose_timer)(const std::thread::id &timer_id, const bool &need_stop)) {
                std::this_thread::sleep_for(std::chrono::milliseconds(duration));
                function();
                dispose_timer(std::this_thread::get_id(), false);
            }, dispose_timer);

    timers.push_back(timer);

    return timer->get_id();
}

void Timer::stop_timer(const std::thread::id &timer_id) {
    dispose_timer(timer_id, true);
}

void Timer::dispose_timer(const std::thread::id &timer_id, const bool &need_stop) {
    if (timers.empty()) return;

    auto timer = std::find_if(timers.begin(), timers.end(), [timer_id](std::thread *timer) {
        return timer->get_id() == timer_id;
    });
    if (timer == timers.end()) return;

    if (need_stop) pthread_cancel((*timer)->native_handle());

    timers.erase(timer);
}

size_t Timer::timers_count() {
    return timers.size();
}
