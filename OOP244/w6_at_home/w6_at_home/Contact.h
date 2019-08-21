
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/04    w6_at_home
///////////////////////////////////////////////////////////

#ifndef Contact_h
#define Contact_h

namespace sict {
    const int MAX_CHAR = 20;
    class Contact{
        char name[MAX_CHAR+1];
        long long* phone = nullptr;
        int num;
    public:
        Contact();
        Contact(const char* cname, const long long* cphone, int size );
        ~Contact();
        bool isEmpty() const;
        void display() const;
        
        Contact(const Contact& ct);
        Contact& operator=(const Contact& rhs);
        Contact& operator+=(long long rhsphone);
        bool isValid(long long temp);

        
    };
};
#endif /* Contact_h */
