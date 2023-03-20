#include "dragon.hpp"

const std::string& Dragon::GetName() const { 
    return name_; 
    }

size_t Dragon::GetAge() const {
     return age_;
     }

size_t Dragon::GetSize() const {
     return size_;
     }

const std::list<Treasure>& Dragon::GetTreasures() const{
    return treasures;
}

std::ostream& operator<<(std::ostream& out, const Dragon& dragon){
    out << "Dragon named: " << dragon.GetName() << ", age: " << dragon.GetAge() << ", size: " 
    << dragon.GetSize() << std::endl;
    out << "Treasures:" << std::endl;
    for ( auto i: dragon.GetTreasures()){
        out << i.name << std::endl;

    }
    return out;

}