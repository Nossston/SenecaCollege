
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/09    ms1
///////////////////////////////////////////////////////////

#ifndef Date_h
#define Date_h

#define NO_ERROR 0
#define CIN_FAILED 1
#define DAY_ERROR 2
#define MON_ERROR 3
#define YEAR_ERROR 4
#define PAST_ERROR 5


namespace aid{
    
    const int min_year = 2018;
    const int max_year = 2038;
    const int min_date = 751098;
    
    
    class Date{
        int dyear;
        int dmonth;
        int dday;
        int dcomparator ;
        int errorstate;
        void errCode(int errorCode);
    public:
        int errCode() const;
        int mdays(int year, int mon) const;
        Date();
        Date(int yr, int mon, int day);
        bool bad() const;
        
        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator<(const Date& rhs) const;
        bool operator>(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Date& o);
    std::istream& operator>>(std::istream& istr, Date& i);
};
#endif /* Date_h */
