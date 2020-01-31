#include "Clock.hpp"

// We can use namespaces in .cpp files because it won't clutter
// the global namespace like in .hpp files
using namespace std::chrono;

Clock::Clock() {
    float _ = restart();
}

float Clock::getElapsed() {
    time_point<high_resolution_clock> n = high_resolution_clock::now();
    float d = duration_cast<duration<float>>(n - m_TimePoint).count();
    return d;
}

float Clock::restart() {
    float elapsed = getElapsed();
    m_TimePoint = high_resolution_clock::now();
    return elapsed;
}