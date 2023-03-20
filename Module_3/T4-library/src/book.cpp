#include "book.hpp"

#include <ctime>
#include <iostream>


Book::Book (std::string name,std::string author, std::string isbn, bool loaned, Date due_date)
 : name_(name), author_(author), isbn_(isbn), loaned_(loaned), due_date_(due_date) {

}

std::string Book::GetName() const{
    return name_;
}

std::string Book::GetAuthor() const{
    return author_;
}

std::string Book::GetISBN() const{
    return isbn_;
}

bool Book::GetStatus() const{
    return loaned_;
}

Date Book::GetDueDate() const{
    return due_date_;
}

bool Book::Loan(){
    if (loaned_==true) {
        return false;
    } 
    else {
        due_date_ = Date::Today();
        due_date_.month++;
        loaned_=true;
        return true;
    }
}
void Book::Restore(){
    due_date_.day = 0;
    due_date_.month = 0;
    due_date_.year = 0;
    loaned_ = false;
}

void Book::Print() const{
    std::cout << "Book: " << GetName() <<", author: "<<GetAuthor()<< ", ISBN: "<< GetISBN()<<
    ", loaned " << std::boolalpha << GetStatus() <<", due date: "<<due_date_.day<<"."<<due_date_.month<<"."<<
    due_date_.year<<std::endl;
}