
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/12    w7_at_home
///////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "SuperHero.h"

namespace sict {
    SuperHero::SuperHero() : Hero() {
        bouns = 0;
        def = 0;
    };
    SuperHero::SuperHero(const char* nm, int h, int a, int b, int d) : Hero(nm, h , a){
        if (  b > 0 && d > 0) {
            Hero(nm, h, a);
            bouns = b;
            def = d;
        }
        else{
            Hero();
            bouns = 0;
            def  = 0;
        }
    };


    int SuperHero::attackStrength() const{
        return ( isEmpty() ) ? 0 : Hero::attackStrength()+bouns;
    };


    int SuperHero::defend() const{
        return ( isEmpty() ) ? 0 : def;
    }
    
    bool SuperHero::isEmpty() const{
        return (Hero::isEmpty() && bouns == 0 && def == 0);
    }

    const SuperHero& operator*(const SuperHero& first, const SuperHero& second){
        SuperHero fir = first;
        SuperHero sec = second;
        
        int rounds = 0 ;
        
        while(rounds < MAX_ROUNDS && fir.isAlive() && sec.isAlive() ){
            fir -= sec.attackStrength() - fir.defend();
            sec -= fir.attackStrength() - sec.defend();
            rounds++;
        }
        
        std::cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
        
        if (fir.isAlive() ){
            std::cout << fir << " in " << rounds << " rounds."  << std::endl ;
            return first;
        }
        else{
            std::cout << sec << " in " << rounds << " rounds." << std::endl  ;
            return second;
        }
        
    }

}
