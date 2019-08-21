/**************
 ///////////////////////////////////////////////////////////
 // Name        Date    Reason
 // Liu,Yu-Che  6/10    w4_at_home
 ///////////////////////////////////////////////////////////
 **********************************************************/

#ifndef Passenger_h
#define Passenger_h



namespace sict {
    class Passenger{
        char pName [19];
        char destination [19];
        int yr;
        int mt;
        int day;
    public:
        Passenger();
        Passenger(const char* cname, const char* cdes);
        Passenger(const char* cname, const char* cdes, int pyear, int pmonth, int pday);
        bool isEmpty() const;
        void display() const;
        const char* name() const;
        bool canTravelWith(const Passenger& p) const;
    };

};
// bool sict::Passenger::isEmpty()


#endif /* Passenger_h */
