
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/16   ms2
///////////////////////////////////////////////////////////
#ifndef Error_h
#define Error_h

#include <iostream>

namespace aid {
 class Error{
     char* msg;
    
public:
    explicit Error(const char* errorMessage = nullptr);
    ~Error();
    void clear();
    bool isClear() const;
    void message(const char* str);
    const char* message() const;
    
    };
    std::ostream& operator<<(std::ostream& os, const Error& er);
}


#endif /* Error_h */
