#include "pokemon.hpp"
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <algorithm>

bool sort_name(const std::pair<std::string, size_t> &x, const std::pair<std::string, size_t> &y) {
    return (x.first[0] < y.first[0]);
}

bool sort_id(const std::pair<std::string, size_t> &x, const std::pair<std::string, size_t> &y) {
    return (x.second < y.second);
}

bool sort_alpha(const std::pair<std::string, size_t> &x, const std::pair<std::string, size_t> &y)
{
    return (x.first[0] < y.first[0]);
}

PokemonCollection::PokemonCollection(PokemonCollection collection,
                    PokemonCollection collection2){
    std::copy(collection.begin(), collection.end(), std::back_inserter(pokemons_));
    std::copy(collection2.begin(), collection2.end(), std::back_inserter(pokemons_));
    pokemons_.sort(sort_alpha);
    auto unique_e = std::unique(pokemons_.begin(),pokemons_.end());
    pokemons_.erase(unique_e, pokemons_.end());
                    }

void PokemonCollection::Add(const std::string& name, size_t id){
    pokemons_.push_back(std::make_pair(name, id));
}

bool PokemonCollection::Remove(const std::string& name, size_t id){
    
    auto it = std::find(pokemons_.cbegin(), pokemons_.cend(), make_pair(name, id));
    
    if (it != pokemons_.end()){
        pokemons_.erase(it);
        return true;
    }
    return false;
}

void PokemonCollection::Print() const{
    for (auto i = pokemons_.begin(); i != pokemons_.end(); i++){
        std::cout << "id: " << i->second << ", name: "<< i->first << std::endl;
    }
}

void PokemonCollection::SortByName(){
    pokemons_.sort(sort_name);

    for (auto i = pokemons_.begin(); i != pokemons_.end(); i++){
       
        if (i->first == std::next(i,1)->first)
        {
            if (sort_id(*(std::next(i, 1)), *i))
                std::swap(*i, *(std::next(i, 1)));
        }
    }
}

void PokemonCollection::SortById(){

    pokemons_.sort(sort_id);
    for (auto i = pokemons_.begin(); i != pokemons_.end(); i++){
        
        if (i->second == std::next(i, 1)->second)
        {
            if (sort_name(*(std::next(i, 1)), *i))
                std::swap(*i, *(std::next(i, 1)));
        }
    }
}



