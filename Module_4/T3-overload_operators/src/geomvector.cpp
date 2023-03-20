#include "geomvector.hpp"

// Implement operators here
GeomVector operator/(const GeomVector& a, double b){
    return GeomVector(a.x_ / b, a.y_ / b, a.z_ / b);
}

bool GeomVector::operator<(const GeomVector& b){
    if(this->Length()<b.Length()){
        return true;
    }
    return false;
}

bool GeomVector::operator>(const GeomVector& b){
    if(this->Length()>b.Length()){
        return true;
    }
    return false;
}

bool GeomVector::operator==(const GeomVector& b){
    if(this->x_ == b.x_ and this->y_ == b.y_ and this->z_ == b.z_){
        return true;
    }
    return false;
}

bool GeomVector::operator!=(const GeomVector& b){
    if(this->x_ != b.x_ or this->y_ != b.y_ or this->z_ != b.z_){
        return true;
    }
    return false;
}

GeomVector GeomVector::operator+(const GeomVector& a) {
    return GeomVector(a.x_ + x_, a.y_ + y_, a.z_ + z_);
}

GeomVector operator*(double a, const GeomVector& b) {
    return GeomVector(a * b.x_, a * b.y_, a * b.z_);
}

std::ostream &operator<<(std::ostream& out, const GeomVector& a) {
    out << "(" << a.x_ << ", " << a.y_ << ", " << a.z_ << ")";
    return out;
}

double GeomVector::Length() const {
    return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
}