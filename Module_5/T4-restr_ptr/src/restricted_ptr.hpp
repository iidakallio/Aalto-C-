#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS

#include "restricted_ref_counter.hpp"

/*
    Implement a class RestrictedPtr that holds a pointer of any type with at least the following members:
        - default constructor (takes no parameters)
        - constructor with a raw pointer parameter
        - copy constructor
        - destructor
        - copy assignment operator
        - function GetData that takes no parameters and returns the data the raw pointer refers to.
            The data returned should be such that modifying it modifies the data the pointer refers to.
        - function GetPointer that takes no parameters and returns the raw pointer
        - function GetRefCount that takes no parameters and returns an int with the reference count
    
    At any time the objects should keep track of how many references there are to a pointer
    and not allow more than 3 references. If the reference count drops to 0, the referenced
    pointer's memory should be released. If the reference count is already 3 when copying,
    the copier should set it's pointer to nullptr and reference count to 1.
    NOTE: GetPointer, GetData and GetRefCount are needed for the tests to run
*/
template <typename T>
class RestrictedPtr {
public:
    
    RestrictedPtr() : tr_(nullptr), counter_(nullptr){
        counter_ = new RestrictedRefCounter();
        counter_->Increase();
    }

    RestrictedPtr(T *ptr) : tr_(ptr), counter_(nullptr) {
        counter_ = new RestrictedRefCounter();
        if (tr_) {
            counter_->Increase();
        }
    }

    RestrictedPtr(RestrictedPtr<T>& ptr) : tr_(ptr.tr_), counter_(ptr.counter_) {
        if (GetRefCount() == 3) {
            tr_ = nullptr;
            counter_ = new RestrictedRefCounter();
            counter_->Increase();
        } else {
            counter_->Increase();
        }
    }

    // destructors
    ~RestrictedPtr<T>(){
        counter_->Decrease();
        if (counter_->GetCount() == 0) {
            delete tr_;
            delete counter_;
        }
    }

    RestrictedPtr& operator=(const RestrictedPtr<T>& r){
         if (this != &r) {
            counter_->Decrease();
            if (GetRefCount() == 0) {
                delete tr_;
                delete counter_;
            }

            if (GetRefCount() != 3) {
                tr_ = r.tr_;
                counter_ = r.counter_;
                counter_->Increase();
                
            } else {
                tr_ = nullptr;
                counter_ = new RestrictedRefCounter();
                counter_->Increase();
            }
        }

        return *this;
    }
    
    T& GetData() const {
        return *tr_;
    }

    T* GetPointer() const {
        return tr_;
    }

    int GetRefCount() const {
        return counter_->GetCount();
    }

    T& operator*() const{
        // return a reference to the object
        return *tr_;
    }
    T* operator->() const{
        // return the object pointer
        return tr_;
    }

private:
    RestrictedRefCounter* counter_;
    T* tr_;  //variable
};
#endif