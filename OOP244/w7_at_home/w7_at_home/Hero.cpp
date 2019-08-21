
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/12    w7_at_home
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include "Hero.h"


namespace sict {
    
    Hero::Hero(){
        name[0] = '\0' ;
        hp = 0;
        attack = 0;
    }
    Hero::Hero(const char* hname, int hhp, int hatk){
        if ( hname != nullptr && hname[0] != '\0' && hhp > 0 && hatk > 0){
            strncpy(name, hname, 39);
            name[40] = '\0';
            hp=hhp;
            attack = hatk;
        }
        else
            *this = Hero();
    };
    void Hero::operator-=(int attack){
        if( attack > 0){
            hp -= attack;
        }
        if ( hp < 0 )
            hp = 0;
    };
    bool Hero::isAlive() const{
        return ( hp > 0 );
    };
    bool Hero::isEmpty() const{
        return (  name[0] == '\0' || attack == 0  );
    };
    int Hero::attackStrength() const{
        return ( isEmpty() ) ? 0 : attack;
    };
    const Hero& operator*(const Hero& first, const Hero& second){
        Hero fir = first;
        Hero sec = second;
        int rounds = 0 ;
        
        while(rounds < MAX_ROUNDS && fir.isAlive() && sec.isAlive() ){
            fir -= sec.attackStrength();
            sec -= fir.attackStrength();
            rounds++;
        }
        
        std::cout<<"Ancient Battle! " << fir << " vs " << sec << " : Winner is ";
        
        if (fir.isAlive() ){
            std::cout << fir << " in " << rounds << " rounds."  << std::endl ;
            return first;
        }
        else{
            std::cout << sec << " in " << rounds << " rounds." << std::endl  ;
            return second;
        }
        
    };
    
    
    std::ostream& operator<<(std::ostream& os, const sict::Hero& hero){
        if (hero.isEmpty())
            os << "No hero";
        else
            os << hero.name;
        return os;
    };
    
    
};

