#ifndef PRINTERS_CLASS
#define PRINTERS_CLASS

#include <sstream>
#include <iostream>
#include <map>
#include "string_printer.hpp"
/* Add include guards here */

class Printers{
public:
    Printers(){
        printers_ = {};
    }
    ~Printers();
    Printers(const Printers& p){
        for (auto i : p.printers_) {
          std::string name= i.first;
          StringPrinter *s = i.second->Clone();
          printers_.insert(make_pair(name, s));
        }
    }
    void Add(std::string name, StringPrinter *p);
    Printers &operator=(Printers &p);
    StringPrinter &operator[](std::string name);


private:
    std::map<std::string, StringPrinter *> printers_;
};
/**
 * @brief: A storage for StringPrinter pointers associated with a name. The
 * class has ownership of the objects.
 * 
 * TODO: Implement the following:
 * ------------
 * Functions:
 * 
 * A default constructor that initializes the object with zero printers.
 * 
 * A copy constructor that copies the object.
 * 
 * Add: A function that adds a new StringPrinter object to the collection
 * and associates it with a name.
 * Takes two parameters:
 *  - a string that contains the name
 *  - the StringPrinter pointer to be added
 * Throws:
 *  - std::invalid_argument if an association for the name already exists ("Duplicate index").
 *  - std::invalid_argument if the pointer is null ("Invalid printer").
 * Note: The Printers object takes ownership of the pointer and is
 *  therefore responsible for eventually calling delete on the pointer.
 * 
 * Indexing operator: The collection is indexed using the
 * name (string) and returns a reference to the associated StringPrinter.
 * Throws:
 *  - std::invalid_argument if an association does not exist ("Unknown index").
 * 
 * Copy assignment operator: copies the object given to self.
 * ------------
 * Members:
 * Whatever you deem necessary.
 * ------------
 * Other:
 * Copying means copying the contained StringPrinters as well.
 * Remember to also implement the destructor.
 */
#endif
