//
//  SpellChecker.c
//  w5_home
//
//  Created by Noston Liu on 2019/10/9.
//  Copyright � 2019 Noston. All rights reserved.
//
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/17 , 2019
#include <fstream>
#include "SpellChecker.h"

using namespace std;

namespace sdds{
    
    SpellChecker::SpellChecker(const char* filename){
        size_t cnt = 0;
        ifstream file(filename);
        string temp;
        string line[10];
        
        if (!file) throw("Bad file name!");
        
        do
        {
            
            std::getline(file, temp);
            
            if (temp[0] != '\0')
            {
                line[cnt] = temp;
                cnt++;
            }
            
        } while (file);
        
        for (size_t i = 0; i < cnt; i++)
        {
            auto bad_end = line[i].find(' ');
            m_badWords[i] = line[i].substr(0, bad_end);
            m_badWords[i].erase(0, m_badWords[i].find_first_not_of(" "));
            m_badWords[i].erase(m_badWords[i].find_last_not_of(" ") + 1);
            auto good_end = line[i].find('\r', bad_end + 1);
            m_goodWords[i] = line[i].substr(bad_end + 1, good_end - bad_end - 1);
            m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(" "));
            m_goodWords[i].erase(m_goodWords[i].find_last_not_of(" ") + 1);
        }
        file.close();
    };
    void SpellChecker::operator()(std::string& text) const{
        size_t bad_at = 0;
        for (int i = 0; i < MAX ; i++) {
            bad_at = text.find( m_badWords[i]) ; // where the bad word is
            while( bad_at != string::npos){
                text.replace( bad_at, m_badWords[i].length() , m_goodWords[i]);
                bad_at = text.find(m_badWords[i]);
            }
        }
    };
    
}
