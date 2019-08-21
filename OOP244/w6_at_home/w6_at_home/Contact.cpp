
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
        name[MAX_CHAR] = '\0';
        num = 0;
        for (int i = 0; i < size ; i++)
        {
            if(isValid(cphone[i]) ){
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
    phone = nullptr;
};

bool Contact::isEmpty() const{
    return ( name[0] == '\0' && phone == nullptr && num == 0 ) ? true : false;
};

void Contact::display() const{
    if( isEmpty() ){
        cout<< "Empty contact!" << endl;
    }
    else if (!isEmpty()){
        cout<< name <<endl;
        for (int i = 0; i < num; i++) {
            int ncode = phone[i] /   10000000000;
            int acode = (phone[i] %  10000000000) / 10000000;
            int mcode = ((phone[i] % 10000000000) % 10000000) / 10000;
            int lcode = ((phone[i] % 10000000000) % 10000000) % 10000;
            cout << "(+" << ncode << ") " << acode << " " << mcode << "-";
            cout.fill('0');
            cout.width(4);
            cout << lcode << endl;
        }
    }
};


Contact::Contact(const Contact& ct){
    *this=ct;
};

Contact& Contact::operator=(const Contact& rhs){
 if(this != &rhs){
    if ( !rhs.isEmpty() ) {
        
        strncpy(name, rhs.name, MAX_CHAR );
        name[MAX_CHAR] = '\0';
        
        delete [] phone;
        phone = nullptr;
        
        num = rhs.num;
        phone = new long long[num]; // num is already the same as rhs.num.
        
        for (int i = 0; i < num ; i++ ) {
            if( isValid(rhs.phone[i]) ){
                // In the instruction, we are not asked to check numbers are valid or not in = operator.
                // However, I consider it is better to have one, or ugly things will be displayed.
                phone[i] = rhs.phone[i];
            }
        }
    }
    else{
        num = 0;
        name[0] = '\0';
        phone = nullptr;
    }
 }
        return *this;
};

Contact& Contact::operator+=(long long rhsphone){
  if ( isValid(rhsphone) && name[0] != '\0' ) {
      
    long long *prhsphone = new long long [num+1];
    for (int i = 0; i < num ; i++)
    {
        prhsphone[i] = phone[i];
    }
    delete [] phone;
    phone = nullptr;
    
    phone = prhsphone;
    
    prhsphone = nullptr;
    
    phone[num] = rhsphone;
    num++;
  }
  return *this;
};


bool Contact::isValid(long long temp){
    int ncode = temp / 10000000000;
    int acode = (temp % 10000000000) / 10000000;
    int rcode = (temp % 10000000000) % 10000000;
    return (ncode > 0 && ncode <100 && acode > 99 && acode < 1000 && rcode >= 1000000 ) ? true : false;
};
