#include "aviary.hpp"

void Aviary::Add(Bird* b_){
    if (b_ != NULL){
        birds_.push_back(b_);
    } else {
        throw std::logic_error("pointer is empty");
    }
    
}

void Aviary::SpeakAll(std::ostream& os) const{
    for (auto it : birds_){
        it->Speak(os);
    }
}

int Aviary::Size() const{
    return birds_.size();
}

Bird* Aviary::operator[](size_t a){
    if (a<birds_.size()){
        return birds_[a];
    } else {
        throw std::out_of_range("index is out of bounds");
    }
}

const Bird* Aviary::operator[](size_t a) const{
    if (a<birds_.size()){
        return birds_[a];
    } else {
        throw std::out_of_range("index is out of bounds");
    }
}


Aviary::~Aviary(){
    for(auto it : birds_) {
        delete it;
    }
}

Aviary& Aviary::operator=(const Aviary& a){
    a.Size();
    return *this;
}