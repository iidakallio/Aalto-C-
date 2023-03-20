#include "standard_printer.hpp"

StringPrinter  *StandardPrinter::Clone()const{
    return new StandardPrinter(*this);
}

StringPrinter &StandardPrinter::operator()(const std::string &str){
    this->os_ << str << std::endl;
    return *this;
}