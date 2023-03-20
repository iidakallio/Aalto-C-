#include "dragon_cave.hpp"

// Define DragonCave's methods here

const std::list<Dragon*> &DragonCave::GetDragons() const{
    return dragons;
}
void DragonCave::Accommodate(Dragon* dragon){
    dragons.push_back(dragon);
}

void DragonCave::Evict(const std::string& name){
    for (std::list<Dragon*>::iterator i = dragons.begin(); i != dragons.end(); i++){
        if ( (*i)->GetName() == name){
            i=dragons.erase(i);
            break;
        }
    }
}

DragonCave::~DragonCave(){
    for(auto i : dragons){
        delete i;
    }   
}

std::ostream& operator<<(std::ostream& os, const DragonCave& cave){
    os << "DragonCave dwellers:"<<std::endl;
    for (auto i : cave.GetDragons()){
        os<<std::endl;
        os<< *i;
    }
    return os;
}