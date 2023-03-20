#include "diagonal_printer.hpp"

StringPrinter *DiagonalPrinter::Clone()const{
    return new DiagonalPrinter(first_line_, last_line_, os_);
}

StringPrinter &DiagonalPrinter::operator()(const std::string &str){
    int number_of_lines = str.size();
    int count = 0;
    if (first_line_.size() != 0){
        this->os_ << first_line_ << std::endl;
    }
    for(size_t i = 0; i != str.size(); i++){
        for(int j = 0; j!=count; j++){
            this->os_ << " ";
        }
        this->os_ << str[i];
        for(int j = number_of_lines; j!=count+1; j--){
            this->os_ << " ";
        }
        this->os_ << std::endl;
        count++;
    }
    if(last_line_.size()!=0){
        this->os_ << last_line_ << std::endl;
    }
    return *this;
};   