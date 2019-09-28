
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/04    w6_at_home
///////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;
using namespace sict;

Contact::Contact(){
    name[0] = '\0';
    phone = nullptr;
    num = 0;
};

Contact::Contact(const char* cname, const long long* cphone, int size ){
    
    if( cname == nullptr || cname[0] == '\0')
        *this = Contact();
    else{
        long long temp[size];
        
        strncpy(name, cname, MAX_CHAR);
        name[MAX_CHAR]= '\0';
        num = 0;
        for (int i = 0; i < size; i++)
        {
            int ncode = cphone[i] / 10000000000;
            int acode = (cphone[i] % 10000000000) / 10000000;
            int rcode = (cphone[i] % 10000000000) % 10000000;
            if(ncode > 0 && ncode <100 && acode > 99 && acode < 1000 && rcode >= 1000000)
            {
                temp[num] = cphone[i];
                num++;
            }
        }
        phone = new long long [num];
        for (int i = 0; i < num; i++) {
            phone[i] = temp[i];
        }
        
    }
};

Contact::~Contact(){
    delete [] phone;
};

bool Contact::isEmpty() const{
    return ( name[0] == '\0' && phone == nullptr && num == 0 ) ? true : false;
};

void Contact::display() const{
    if(isEmpty()){
        cout<< "Empty contact!" << endl;
    }
    else if (!isEmpty()){
        cout<< name <<endl;
        for (int i = 0; i < num; i++) {
            int ncode = phone[i] / 10000000000;
            int acode = (phone[i] % 10000000000) / 10000000;
            int mcode = ((phone[i] % 10000000000) % 10000000) / 10000;
            int lcode = ((phone[i] % 10000000000) % 10000000) % 10000;
            cout << "(+" << ncode << ") " << acode << " " << mcode << "-";
            cout.fill('0');
            cout.width(4);
            cout << lcode << endl;
        }
    }
};

