#include "aircraft.hpp"
//TODO: implement Aircraft's members

Aircraft::Aircraft(std::string register_number,
             std::string owner,
             std::string model,
             double wingspan,
             unsigned int cruise_speed):Vehicle(register_number, owner){
                 model_=model;
                 wingspan_ = wingspan;
                 cruise_speed_ = cruise_speed;
             }

void Aircraft::Write(std::ostream& stream){
    stream << "A;"<<GetRegisterNumber()<<";"<<GetOwner()<<";"<< model_ << ";"
           << wingspan_ << ";"<< cruise_speed_ << std::endl;
}

void Aircraft::Print(){
    Write(std::cout);
}

Aircraft* Aircraft::Read(std::istream& stream){
    if(stream.rdstate() & (stream.failbit | stream.badbit)){
        return NULL;
    } else{
        std::string semicolon;
        std::string register_number;
        std::string owner;
        std::string model;
        std::string input;
        double wingspan;
        unsigned int cruise_speed;
        char buffer = stream.peek();
        std::string line;

        if (buffer != 'A') {
            return NULL;
        }
            std::getline(stream, semicolon, ';');
            std::getline(stream, register_number, ';');

            std::getline(stream, owner, ';');
            std::getline(stream, model, ';');

            std::getline(stream, input, ';');
            wingspan = std::stod(input);

            std::getline(stream, input, ';');
            cruise_speed = std::stoul(input);

            Aircraft *newaircraft = new Aircraft(register_number, owner, model, wingspan, cruise_speed);
            return newaircraft;
        

        
    }


}