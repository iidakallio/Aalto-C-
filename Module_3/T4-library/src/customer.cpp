#include "customer.hpp"
#include "book.hpp"
#include <iostream>

Customer::Customer(std::string name, std::string id) 
 : name_(name), id_(id) {

 }

std::string Customer::GetName() const{
    return name_;
}

std::string Customer::GetID() const{
    return id_;
}

int Customer::GetLoanAmount() const{
    return books_.size();
}

Books Customer::GetLoans() const{
    return books_;
}

bool Customer::LoanBook(Book& b){
    bool loan = b.Loan();
    if(loan){
        books_.push_back(b);
    }
    return loan;
}

void Customer::ReturnBook(Book& b){
    for (std::vector<Book>::size_type i=0; i<books_.size(); i++) {
        if (books_[i].GetISBN()==b.GetISBN()){
            books_.erase(books_.begin()+i);
        }
    }
    b.Restore();

}

void Customer::Print() const{
    std::cout << "Customer: "<<GetName()<<", "<<GetID()<<", has " 
    <<GetLoanAmount() <<" books on loan:"<<std::endl;
    for (auto it:books_){
        std::cout << "- ";
        it.Print();
    }
}
