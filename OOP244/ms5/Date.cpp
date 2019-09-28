
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/09    ms1
///////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

namespace aid{
    
    void Date::errCode(int errorCode){
        errorstate = errorCode;
    };
    
    int Date::errCode() const{
        return errorstate;
    };
    
    int Date::mdays(int year, int mon) const{
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    };
    
    Date::Date(){
        dmonth = 0;
        dyear = 0;
        dday = 0;
        dcomparator = 0;
        errorstate = NO_ERROR ;
    };
    
    Date::Date(int yr, int mon, int day){
        dcomparator = ( yr*372 + mon*31 + day );
        if( yr <= min_year || yr >= max_year  ){
            *this = Date();
            errCode(YEAR_ERROR);
            
        }
        else if ( mon < 1 || mon > 12){
            
            *this = Date();
            errCode(MON_ERROR);
        }
        else if ( day < 1  || day > mdays(yr, mon) ){
            
            *this = Date();
            errCode(DAY_ERROR);
        }
        
        else if ( dcomparator < min_date){
            
            errCode(PAST_ERROR);
        }
        else {
            
            dyear = yr;
            dmonth = mon;
            dday = day;
            errCode(NO_ERROR);
        }
    };
    
    bool Date::bad() const{
        return (errCode() == NO_ERROR) ? false : true;
    };
    
    std::istream& Date::read(std::istream& istr){
        char single;
        istr.clear();
        istr >> dyear >> single >> dmonth >> single >> dday ;
        dcomparator = dyear*372 + dmonth*31 + dday;
        
        if ( istr.fail() ) {
            *this =Date();
            errCode(CIN_FAILED);
        }
        else if( dyear < min_year || dyear > max_year  ) {
            *this =Date();
            errCode(YEAR_ERROR);
        }
        else if ( dmonth < 1 || dmonth > 12) {
            *this =Date();
            errCode(MON_ERROR);
        }
        else if (  dday > mdays(dyear, dmonth)) {
            *this =Date();
            errCode(DAY_ERROR);
        }
        else if ( dcomparator < min_date) {
            *this = Date();
            errCode(PAST_ERROR);
        }
        else {
            errCode(NO_ERROR);
        }
        return istr;
    };
    
    std::ostream& Date::write(std::ostream& ostr) const{
        
        ostr << dyear << "/" << std::setfill('0') << std::setw(2) << dmonth << "/" << std::setfill('0') << std::setw(2) << dday;
        return ostr;
    };
    
    std::ostream& operator<<(std::ostream& ostr, const Date& o){
        return o.write(ostr);
    };
    std::istream& operator>>(std::istream& istr, Date& i){
        return i.read(istr);
    };
    
    bool Date::operator==(const Date& rhs) const{
        return ( dcomparator == rhs.dcomparator) ? true : false ;
    };
    bool Date::operator!=(const Date& rhs) const{
        return ( dcomparator != rhs.dcomparator)  ? true : false ;
    };
    bool Date::operator<(const Date& rhs) const{
        return ( dcomparator < rhs.dcomparator) ? true : false ;
    };
    bool Date::operator>(const Date& rhs) const{
        return ( dcomparator > rhs.dcomparator) ? true : false;
    };
    bool Date::operator<=(const Date& rhs) const{
        return ( dcomparator >= rhs.dcomparator) ? true : false;
    };
    bool Date::operator>=(const Date& rhs) const{
        return !( dcomparator < rhs.dcomparator) ? true : false;
    };
    
};
