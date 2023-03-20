#include "magic_dragon.hpp"

// Define MagicDragon's methods here

 void MagicDragon::Eat(std::list<Food> &list_foods){
    for (std::list<Food>::iterator i=list_foods.begin(); i!=list_foods.end(); i++)
        {
        if (i->type == Herbs)
            {
                this->size_++;
                std::cout << "Magic dragon ate: " << i->name << std::endl;
                list_foods.erase(i);
            }
    }

 }
void MagicDragon::Hoard(std::list<Treasure> &list_treasures){
 for (std::list<Treasure>::iterator i = list_treasures.begin(); i != list_treasures.end(); i++)
    {
        if (i->type == Potions){
            treasures.push_back(*i);
            std::cout << "Magic dragon received: " << i->name << std::endl;
            list_treasures.erase(i);
        }

    }  
}