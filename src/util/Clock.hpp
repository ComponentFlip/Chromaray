#pragma once

#include <chrono>

class Clock {
public:
    Clock();
public:
    float getElapsed();
    float restart();
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_TimePoint;
};