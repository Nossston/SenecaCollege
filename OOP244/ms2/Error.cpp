
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/16   ms2
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include "Error.h"

namespace aid {
    
    
    Error::Error(const char* errorMessage){
        if (errorMessage != nullptr && errorMessage[0] != '\0'){
            msg = new char[strlen(errorMessage)+1];
            strncpy(msg,errorMessage,strlen(errorMessage));
            msg[strlen(errorMessage)] = '\0';
        }
        else {
            msg = nullptr;
        }
    };
    Error::~Error(){
        delete [] msg;
        msg = nullptr;
    }
    void Error::clear(){
        delete [] msg;
        msg = nullptr;
        
    };
    bool Error::isClear() const{
        return (msg == nullptr );
    };
    void Error::message(const char* str){
        delete [] msg;
        msg = nullptr;
        if (str != nullptr && str[0] != '\0') {
            msg = new char[strlen(str) + 1];
            strncpy(msg, str, strlen(str));
            msg[strlen(str)] = '\0';
        }
        else{
            delete [] msg;
            msg = nullptr;
        }
    };
    const char* Error::message() const{
        return (msg == nullptr) ? nullptr : msg ;
    };
    std::ostream& operator<<(std::ostream& os, const Error& er){
        if( !er.isClear() ){
            os << er.message();
        }
            return os;
    };
}
