#ifndef DIAGONAL_PRINTER_CLASS
#define DIAGONAL_PRINTER_CLASS

#include <sstream>
#include <iostream>
#include "string_printer.hpp"

/* Add include guards here */

class DiagonalPrinter : public StringPrinter{
public:
    DiagonalPrinter(std::string first = "", std::string last = "", 
    std::ostream &os = std::cout) : StringPrinter(os), first_line_(first), last_line_(last){}
    virtual StringPrinter *Clone()const;
    virtual StringPrinter &operator()(const std::string &str);

private:
    std::string first_line_;
    std::string last_line_;
};
/**
 * @brief A class that is used to print strings diagonally (see below). The
 * class inherits (public inheritance) class StringPrinter.
 * 
 * TODO: Implement the following:
 * ------------
 * Functions:
 * 
 * A constructor that takes three parameters:
 *  - The first line, which is "" by default, i.e. it is not printed at all
 *  - The last line, which is "" by default, i.e. it is not printed at all either
 *  - A reference to the output stream, which is std::cout by default
 * 
 * Overrides the necessary members from the base class.
 * ------------
 * Other:
 * DiagonalPrinter prints a string diagonally. For the string "like this":
<first line>\n
l        \n
 i       \n
  k      \n
   e     \n
         \n
     t   \n
      h  \n
       i \n
        s\n
<last line>\n
 * where <first line> and <last line> are replaced by the strings given in the
 * constructor. If the first line is empty, it is not printed. The same applies
 * to the last line.
 */

#endif