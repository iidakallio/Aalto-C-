#include "register.hpp"
#include <fstream>
#include <sstream>
#include "aircraft.hpp"
#include "boat.hpp"
//TODO: implement Register's members


Register::~Register(){
    for (auto i : vehicles_)
    {
        delete i;
    }
    vehicles_.clear();
}


void Register::Add(Vehicle* v){
    vehicles_.push_back(v);
}

void Register::Save(const std::string& filename) const{
    std::ofstream os(filename);
    for(auto i: vehicles_){
        i->Write(os);

    }
}


bool Register::ReadLine(std::istream& stream) {
    /*if (stream.rdstate() & (stream.failbit | stream.badbit)) {
        return false;
    } */

    Vehicle* vehicle = Aircraft::Read(stream);
    if (vehicle == NULL) {
        vehicle = Boat::Read(stream);
    }
    if (vehicle) {
        Add(vehicle);
        return true;
    }
    std::string line;
    std::getline(stream, line);
    return false;
}

int Register::Load(const std::string& filename){
    std::ifstream is(filename);
    int num = 0;
    if (is.rdstate() & (is.failbit | is.badbit)){
         return -1;
    }
       
    else{
        
        while (!is.eof()){
            std::string line;
            std::getline(is, line);
            std::istringstream iss(line);
            if (ReadLine(iss)==true)
                num++;

        }
    return num;
    }
}
        
void Register::Print(){
    for (auto i:vehicles_){
        i->Print();
    }

}


size_t Register::Size() const{
    return vehicles_.size();
}