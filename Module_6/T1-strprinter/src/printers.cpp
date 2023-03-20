#include "printers.hpp"

Printers::~Printers(){
    for(auto i : printers_) {
        if(i.second){
            delete i.second;
            i.second = nullptr;
        }
    }
    printers_.clear();
}

void Printers::Add(std::string name, StringPrinter *p){
    for (std::map<std::string, StringPrinter *>::iterator i = printers_.begin()
    ; i != printers_.end(); i++)
    {
        if (name == i->first){
            throw std::invalid_argument("Duplicate index");
        }
    }
    if (p == nullptr){
        throw std::invalid_argument("Invalid printer");
    }

    printers_.insert(make_pair(name,p));
}

Printers &Printers::operator=(Printers &p){
    for(auto i : printers_) {
        if(i.second){
            delete i.second;
            i.second = nullptr;
        }
    }
    printers_.clear();
      

    for (auto i : p.printers_) {
        std::string name= i.first;
        StringPrinter *s = i.second->Clone();
        printers_.insert(make_pair(name, s));
    }
    return *this;
}
StringPrinter &Printers::operator[](std::string name){
    /*bool found = false;
    for(auto i=printers_.begin();i!=printers_.end();i++){
        if(i.first = name){
            found = true;
        }
    }
    if(found=false)*/
    std::map<std::string, StringPrinter *>::iterator it = printers_.find(name);
    if(it  == printers_.end()){
        throw std::invalid_argument("Unknown index");
    }
    return *(printers_[name]);
    
}