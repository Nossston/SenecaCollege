/**********************************************************
 ///////////////////////////////////////////////////////////
 // Name        Date    Reason
 // Liu,Yu-Che  6/05    w4_in_lab
 ///////////////////////////////////////////////////////////
 **********************************************************/

#ifndef Passenger_h
#define Passenger_h



namespace sict {
    class Passenger{
        char pName [19];
        char destination [19];
    
    public:
        Passenger();
        Passenger(const char* cname, const char* cdes);
        bool isEmpty() const;
        void display() const;
    };

};

#endif /* Passenger_h */
