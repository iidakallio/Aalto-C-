#include "poly.hpp"

#include <sstream>

int Poly::operator[](int exp) const {
    auto it = values_.find(exp);
    return it == values_.end() ? 0 : it->second;
}

Poly& Poly::operator+=(const Poly& b){
    for (auto i = b.begin(); i != b.end(); i++) {
       
        values_[i->first] += i->second;
    }

    return *this;
}
Poly& Poly::operator-=(const Poly& b){
    for (auto i = b.begin(); i != b.end(); i++) {
        
        values_[i->first] -= i->second;
    }

    return *this;
}

std::istream& operator>>(std::istream& is, Poly& p){
    
    std::string s;
    int multiplier = 0;
    char x;
    int exp = 0;
    std::getline(is, s, ' ');
    if (s.size()==0){
        std::getline(is, s);
    }
    std::stringstream iss(s);
    while(iss >> multiplier >> x >> exp){
        if(multiplier!=0)
            p[exp] += multiplier;

    }

    return is;
}


std::ostream& operator<<(std::ostream& os, const Poly& p){
    if (p.crbegin()==p.crend()){
        return os;
    }
    for(auto i = p.crbegin(); i!=p.crend();i++){
        if(i->second != 0){
            if (i != p.crbegin() && i->second > 0) {
                os << "+";
            }
            if (i->second != 0){
                os << i->second << "x" << i->first;
            }
            
        }
    }
    return os;
}

Poly operator+(const Poly& a, const Poly& b){
    Poly c = b;
    for (auto i=a.begin();i!=a.end();i++){
        c[i->first] += i->second;
    }
    return c;

}

Poly operator-(const Poly& a, const Poly& b){
    Poly c = a;
    for (auto i=b.begin();i!=b.end();i++){
        c[i->first] -= i->second;
    }
    return c;
}

Poly operator-(const Poly& p){
    Poly a=p;
    
    for(auto i=p.begin(); i!=p.end(); i++){
        a[i->first] = -a[i->first];
    }
    return a;
}



bool operator<(const Poly& a, const Poly& b){
    auto it1 = a.crbegin();
    auto it2 = b.crbegin();
    if((it1 == a.crend() && it2 == b.crend()) || (it1 != a.crend() && it2 == b.crend())){
        return false;
    }
    if(it1 == a.crend() && it2 != b.crend()){
        return true;
    }
    return it1->first < it2->first;
}

bool operator==(const Poly& a, const Poly& b){
    auto it1 = a.crbegin();
    auto it2 = b.crbegin();
    if (it1 == a.crend() && it2 == b.crend()){
        return true;
    }
    if (it1 == a.crend() || it2 == b.crend()){
        return false; 
    } 
    
    return it1->first == it2->first;
    
}

bool operator>(const Poly& a, const Poly& b){
    auto it1 = a.crbegin();
    auto it2 = b.crbegin();
    if((it1 == a.crend() && it2 == b.crend()) || (it1 == a.crend() && it2 != b.crend())){
        return false;
    }
    if(it1 != a.crend() && it2 == b.crend()){
        return true;
    }
    return it1->first > it2->first;
}

bool operator!=(const Poly& a, const Poly& b){
    
    return !(operator==(a,b));
}