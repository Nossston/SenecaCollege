//
//  SongCollection.h
//  w7_lab
//
//  Created by Noston Liu on 2019/11/4.
//  Copyright © 2019 Noston. All rights reserved.
//

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
        std::string m_price;
        std::string s_year;
        std::string s_length;
        std::string timeFormat() const;
    };
    
    class SongCollection{
        std::vector<Song> s_songs;
    public:
        SongCollection(const char* filename);
        void display(std::ostream&) const;
        void sort(std::string );
        void cleanAlbum();
        bool inCollection(std::string ) const;
        std::list<Song> getSongsForArtist(std::string) const;
        std::string trim(std::string&);
    };
    std::ostream& operator<<(std::ostream& out, const Song& theSong);
}


#endif /* SongCollection_h */
