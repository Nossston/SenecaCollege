// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 19th Sept , 2019

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds {
    const int MAX = 7;
    class TimedEvents {
        int count {0};
        std::chrono::steady_clock::time_point timestart;
        std::chrono::steady_clock::time_point timeend;
        struct {
            std::string msg;
            std::string units;
            std::chrono::steady_clock::duration duration;
        } arrayS[MAX];
    public:
        void startClock();
        void stopClock();
        void recordEvent(const char*);
        friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
    };
};
#endif
