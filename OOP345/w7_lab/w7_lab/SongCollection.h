//
//  SongCollection.h
//  w7_lab
//
//  Created by Noston Liu on 2019/11/4.
//  Copyright © 2019 Noston. All rights reserved.
//
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 11/7 , 2019

#ifndef SongCollection_h
#define SongCollection_h

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>

namespace sdds {
    
    struct Song {
        std::string s_arti;
        std::string s_title;
        std::string s_album;
        std::string s_price;
        std::string s_year;
        std::string s_length;
        Song(std::string);
        std::string timeFormat() const;
    };
    
    class SongCollection{
        std::vector<Song> s_songs;
    public:
        SongCollection(const char* filename);
        void display(std::ostream&) const;
    };
    std::ostream& operator<<(std::ostream& out, const Song& theSong);
}


#endif /* SongCollection_h */
