// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 19th Sept , 2019
#include <fstream>
#include <cstring>
#include "Text.h"

using namespace std;

namespace sdds{
    
    Text::Text(){
        count = 0;
        t_string = nullptr;
    };
    
    Text::Text(const char* rhs){
        
        string lines;
       
        fstream myfile;
        myfile.open(rhs);
        
        char x ;
        myfile.clear();
        while ( !myfile.eof() )
        {
            x = myfile.get();
            if ( x == ' '){
                count++;
            }
        }
        
        t_string = new string[count];
        
        for (int i = 0; i < count; i++) {
            getline(myfile, t_string[i]);
        }
        
    };
    
    Text::Text(Text& rhs){
        
        *this = rhs;
        // not this:;
        // count = rhs.count;
        // t_string = rhs.t_string;
    };
    
    Text& Text::operator=(const Text& rhs){
        
        if( this != &rhs )
        {
            count = rhs.count;
            
            delete [] t_string;
            
            t_string = new string[count];
            
            for (size_t i = 0; i < rhs.size(); i++) {
                t_string[i] = rhs.t_string[i];
            }
        }
        return *this;
    };
    
    Text::~Text(){
        delete [] t_string;
        t_string = nullptr;
    };
    size_t Text::size() const{
        return count;
    };

}
