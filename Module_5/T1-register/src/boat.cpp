#include "boat.hpp"
//TODO: implement Boat's members

Boat::Boat(std::string register_number, std::string owner, std::string name, 
    double draft, double power):Vehicle(register_number, owner){
        name_ = name;
        draft_ = draft;
        power_ = power;
    }

void Boat::Write(std::ostream &stream){
    stream << "B;"<<GetRegisterNumber()<<";"<<GetOwner()<<";"<< name_ << ";"
           << draft_ << ";" << power_ << std::endl;
}

void Boat::Print(){
    Write(std::cout);
}

Boat* Boat::Read(std::istream &stream){
    if(stream.rdstate() & (stream.failbit | stream.badbit)){
        return NULL;
    } else{
        std::string semicolon;
        std::string register_number;
        std::string owner;
        std::string name;
        std::string input_draft;
        std::string input_power;
        double draft;
        double power;

        char buffer = stream.peek();
        std::string line;

        if (buffer != 'B') {
            return NULL;
        }

        std::getline(stream, semicolon, ';');
        std::getline(stream, register_number, ';');

        std::getline(stream, owner, ';');
        std::getline(stream, name, ';');

        std::getline(stream, input_draft, ';');
        draft = std::stod(input_draft);

        std::getline(stream, input_power, ';');
        power = std::stod(input_power);

        Boat *newboat = new Boat(register_number, owner, name, draft, power);
        
        return newboat;
        
    }
}