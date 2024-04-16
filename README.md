# Timer

Timer utility which helps to run a function after a certain time in a separate thread.

### Usage

Run timer

```cpp
void print_hello() {
    std::cout << "Hello!\n";
}

// 1 option
Timer::start_timer(1000, print_hello);

// 2 option
Timer::start_timer(1000, [] {
    std::cout << "Hello!\n";
});
```

Stop timer

```cpp
auto timer_id = Timer::start_timer(3000, print_hello);

// other code

Timer::stop_timer(timer_id);
```

See *main.cpp* for more usage examples.