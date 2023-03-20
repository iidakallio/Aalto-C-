#include "fantasy_dragon.hpp"

// Define FantasyDragon's methods here

void FantasyDragon::Eat(std::list<Food>& list_foods){

    for (std::list<Food>::iterator i=list_foods.begin();
            i!=list_foods.end(); i++)
        {
        if ((i->type == People) or (i->type == PeopleFood))
            {
                this->size_++;
                std::cout << "Fantasy dragon ate: " << i->name << std::endl;
                list_foods.erase(i);
            }
    }

}



void FantasyDragon::Hoard(std::list<Treasure>& list_treasures)
{
    for (std::list<Treasure>::iterator i = list_treasures.begin();
         i != list_treasures.end(); i++)
    {
        if (i->type == Jewellery){
            treasures.push_back(*i);
            std::cout << "Fantasy dragon received: " << i->name << std::endl;
            list_treasures.erase(i);
        }

    }
}