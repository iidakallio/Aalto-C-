#include "vector_strings.hpp"

#include <iostream>
#include <vector>

void Adder(std::vector<std::string>& names) {
    std::string name;
    std::cout << "Enter a name:"<<std::endl;
    std::cin >> name;
    names.push_back(name);
    std::cout << "Number of names in the vector:" << std::endl << names.size()<<std::endl;
}

void Remover(std::vector<std::string>& names) {
    std::string removed_string = names[names.size()-1];
    names.pop_back();
    std::cout << "Removing the last element:" << std::endl<< removed_string << std::endl;

}

void Printer(std::vector<std::string>& names) {
    for(unsigned int i = 0; i < names.size(); i++){
        std::cout << names[i]<< std::endl;
    }
    
}

void CMDReader() {
    std::string command = "yes";
    std::vector<std::string> names;
    std::cout << "Commands: ADD, PRINT, REMOVE, QUIT" << std::endl;
    while (command != "QUIT"){
       
        std::cout << "Enter a command:"<<std::endl;
        std::cin >> command;
        if (command == "ADD"){
            Adder(names);
        } else if(command == "REMOVE"){
            Remover(names);
        } else if(command == "PRINT"){
            Printer(names);
        }
    }
        

}
