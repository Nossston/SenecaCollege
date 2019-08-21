
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/04    w6_in_lab
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
        Contact(const char* cname, const long long* cphone, int num );
        ~Contact();
        bool isEmpty() const;
        void display() const;
    };
};
#endif /* Contact_h */
