#include "library.hpp"

#include <iostream>

#include "book.hpp"
#include "customer.hpp"


Library::Library(std::string name)
 : name_(name) {

 }

 std::string Library::GetName() const{
     return name_;
 }

 std::vector<Book>& Library::GetBooks(){
     return books_;
 }

 std::vector<Customer>& Library::GetCustomers(){
     return customers_;
 }

 Book Library::FindBookByName(std::string name){
     for (std::vector<Book>::size_type it = 0; it<books_.size(); it++){
         if(books_[it].GetName() == name){
             return books_[it];
         }
     }
     return Book("","","");
 }

std::vector<Book> Library::FindBooksByAuthor(std::string author){
    std::vector<Book> lista;
    for (std::vector<Book>::size_type it = 0; it<books_.size(); it++){
         if(books_[it].GetAuthor() == author){
             lista.push_back(books_[it]);
             
         }
     }
     return lista;
 }

 std::vector<Book> Library::FindAllLoanedBooks(){
    std::vector<Book> lista;
    for (std::vector<Book>::size_type it = 0; it<books_.size(); it++){
         if(books_[it].GetStatus()==true){
             lista.push_back(books_[it]);
             
         }
     }
     return lista;
 }

 Customer Library::FindCustomer(std::string id){
    for (std::vector<Customer>::size_type it = 0; it<customers_.size(); it++){
         if(customers_[it].GetID() == id){
             return customers_[it];
         }
     }
     return Customer("","");
 }