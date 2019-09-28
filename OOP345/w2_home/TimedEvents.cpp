// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 19th Sept , 2019

#include <iomanip>
#include "TimedEvents.h"

namespace sdds
{
    void TimedEvents::startClock(){
        timestart = std::chrono::steady_clock::now();
    };
    
    void TimedEvents::stopClock(){
        timeend = std::chrono::steady_clock::now();
    };
    

    void TimedEvents::recordEvent(const char* msg){
        auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(timeend - timestart);
        if (count < MAX)
        {
            arrayS[count].msg = msg;
            arrayS[count].units = "nanoseconds";
            arrayS[count].duration = ms;
            count++;
        }
    };
    
    std::ostream& operator<<(std::ostream& os, const TimedEvents& rhs){
        os << "--------------------------\n";
        os << "Execution Times:\n";
        os << "--------------------------\n";
        for (int i = 0; i < rhs.count; i++){
            os << std::setw(20) << std::left
            << rhs.arrayS[i].msg << ' ' << std::setw(12) << std::right
            << rhs.arrayS[i].duration.count() << ' '
            << rhs.arrayS[i].units << '\n';
        }
        os << "--------------------------\n";
        return os;
    };
}
