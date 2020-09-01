//
//  SongCollection.c
//  w7_lab
//
//  Created by Noston Liu on 2019/11/4.
//  Copyright © 2019 Noston. All rights reserved.
//
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 11/7 , 2019
#include "SongCollection.h"


namespace sdds {
    Song::Song( std::string in){
        s_arti = in.substr(0,25) ;
        s_arti.erase(0,s_arti.find_first_not_of(" "));
        s_arti.erase(s_arti.find_last_not_of(" ") + 1);
        
        s_title = in.substr(25,25);
        s_title.erase(0,s_title.find_first_not_of(" "));
        s_title.erase(s_title.find_last_not_of(" ") + 1);
        
        s_album = in.substr(50,25);
        s_album.erase(0,s_album.find_first_not_of(" "));
        s_album.erase(s_album.find_last_not_of(" ") + 1);
        s_year = in.substr(75,5) ;
        s_year.erase(0,s_year.find_first_not_of(" "));
        s_year.erase(s_year.find_last_not_of(" ") + 1);
        
        s_length = in.substr(80,5 );
        s_length.erase(0,s_length.find_first_not_of(" "));
        s_length.erase(s_length.find_last_not_of(" ") + 1);
        
        s_price = in.substr(85,5);
        s_price.erase(0,s_price.find_first_not_of(" "));
        s_price.erase(s_price.find_last_not_of(" ") + 1);
    };
    std::string Song::timeFormat() const{
        int second = stoi(s_length);
        int minute = second/60;
        int pre_second = second%60;
        std::string temp =  std::to_string(minute) + ":";
        if ( pre_second < 10){
            temp += "0" + std::to_string(pre_second);
        }else{
            temp += std::to_string(pre_second);
        }
        return temp;
    };
    SongCollection::SongCollection(const char* filename){
        std::ifstream file(filename);
        if (!file)
        {
            std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
            return;
        }
        while ( !file.eof() ) {
            std::string tmp;
            getline(file,tmp, '\n');
            Song temp_song(tmp);
            s_songs.push_back(temp_song);
        }
    };
    
    // don't use manual for-loop
    void SongCollection::display(std::ostream& os) const{
        for_each( this->s_songs.begin() , this->s_songs.end(), [&os](const Song& songs){ os << songs << std::endl;} );
      //  for( auto i : s_songs){
      //      os << i  << std::endl;
      //  }
    }
    
    
    
    std::ostream& operator<<(std::ostream& out, const Song& theSong){
        
       // std::string bar = "| ";
        out
        << "| " << std::setw(20) << std::left << theSong.s_arti
        << " | " << std::setw(15) << std::left << theSong.s_title
        << " | " << std::setw(20) << std::left << theSong.s_album
        << " | " << std::setw(6) << std::right << theSong.s_year
        << " | " << theSong.timeFormat()
        << " | " << std::fixed << std::setprecision(2) << theSong.s_price <<" |";
        return out;
    };
}
