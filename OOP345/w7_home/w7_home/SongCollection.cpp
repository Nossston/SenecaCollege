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
#include <numeric>
#include <list>
//#include <>

#include "SongCollection.h"


namespace sdds {
    std::string SongCollection::trim(std::string& in){
        
        in.erase(0,in.find_first_not_of(" "));
        in.erase(in.find_last_not_of(" ") + 1);
        return in;
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
            std::string in;
            getline(file,in, '\n');
            Song song;
            
            song.s_title = in.substr(0,25) ;
            trim(song.s_title);
    
            song.s_arti = in.substr(25,25);
            trim(song.s_arti);
            song.s_album = in.substr(50,25);
            trim(song.s_album);
            song.s_year = in.substr(75,5) ;
            trim(song.s_year);

            song.s_length = in.substr(80,5 );
            trim(song.s_length);

            song.m_price = in.substr(85,5);
            trim(song.m_price);

            s_songs.push_back(song);
        }
    };
    
    // don't use manual for-loop
    void SongCollection::display(std::ostream& os) const{
        for_each( this->s_songs.begin() , this->s_songs.end(), [&](const Song& songs){ os << songs << std::endl;} );
        //  for( auto i : s_songs){
        //      os << i  << std::endl;
        //  }
        
        
        os << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
        std::string col = ":";
        int sum = std::accumulate(s_songs.begin() , s_songs.end(), 0, [&](auto stock,const Song& tmp){return stock += stoi(tmp.s_length);} );
        os << "|"<< std::setw(78) <<  "Total Listening Time: " << sum/3600
        << col << (sum/60)%60
        << col << sum%60 << " |" << std::endl ;
    }
    
    
    
    std::ostream& operator<<(std::ostream& out, const Song& theSong){
        
        // std::string bar = "| ";
        out
        << "| " << std::setw(20) << std::left << theSong.s_title
        << " | " << std::setw(15) << std::left << theSong.s_arti
        << " | " << std::setw(20) << std::left << theSong.s_album
        << " | " << std::setw(6) << std::right << theSong.s_year
        << " | " << theSong.timeFormat()
        << " | " << std::fixed << std::setprecision(2) << theSong.m_price <<" |";
        return out;
    };
    
    void SongCollection::sort(std::string type){
        if (type == "title") {
            std::sort(this->s_songs.begin(), this->s_songs.end() ,
                      []( const Song& tmp ,const Song& rhs){ return tmp.s_title < rhs.s_title;} );
        }
        else if (type == "album" ){
            std::sort(this->s_songs.begin(), this->s_songs.end() ,
                      []( const Song& tmp ,const Song& rhs) { return tmp.s_album < rhs.s_album;} );
        }
        else if ( type == "length" ){
            std::sort(this->s_songs.begin(), this->s_songs.end() ,
                      []( const Song& tmp ,const Song& rhs) { return tmp.s_length < rhs.s_length;} );
        }
        else{
            std::cout << "invalid request";
        }
    };
    void SongCollection::cleanAlbum(){
        for_each( this->s_songs.begin() , this->s_songs.end(),
                 [](Song& tmp) { if(tmp.s_album == "[None]" ) tmp.s_album="" ;}  );
    };
    bool SongCollection::inCollection(std::string name) const{
        auto find = std::find_if(s_songs.begin(),s_songs.end(), [&](const Song& tmp){return tmp.s_arti == name; });
        auto result = find == s_songs.end() ? false : true;
        return result;
    };
    std::list<Song> SongCollection::getSongsForArtist(std::string name) const{
        auto count  = std::count_if(s_songs.begin() , s_songs.end(), [&](const Song& a) {return a.s_arti == name;}  );
        std::list<Song> tmp(count);
        //std::list<Song> tmp ;
        std::copy_if(s_songs.begin(), s_songs.end(), tmp.begin(), [&](const Song& b ) {return b.s_arti == name; } );
        
        return tmp;
    };
}
