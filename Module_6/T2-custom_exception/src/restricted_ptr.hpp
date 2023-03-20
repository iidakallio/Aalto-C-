#ifndef RESTRICTED_PTR_CLASS
#define RESTRICTED_PTR_CLASS


#include "restricted_ref_counter.hpp"
/* Add include guards here */

/* 
 * Copy your implementation from the last round here (or wait for
 * the example answer to come out and copy that) and wrap it inside a 
 * WeirdMemoryAllocator namespace.
 * 
 * Changes to the class:
 * 
 * Add a new member string to store the use of the RestrictedPtr 
 * and add a new string parameter, which is the use of the pointer, to the 
 * constructor that originally only takes a pointer. Remember to modify
 * copying to also copy the use. If the pointer is automatically set to 
 * a nullptr (i.e. not given in the constructor), the use is "nullptr".
 * 
 * The copy constructor and assigment operators should throw a RestrictedCopyException 
 * if the operations fail (as they in some cases should). When the copying
 * fails, only the exception should be thrown and no changes should be made
 * to the existing pointer.
 * 
 * The GetData function should throw a RestrictedNullException with the use
 * of the RestrictedPtr given to it if the pointer is null.
 * 
 * The class shouldn't leak any memory.
*/
namespace WeirdMemoryAllocator {
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

        RestrictedPtr(const RestrictedPtr<T>& r){
            
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
                return *this;
            } else{
                throw RestrictedCopyException();
            }

            
        }
        
        T& GetData() const {
            if(*tr == "nullptr"){
                throw RestrictedNullException();
            }
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
}

#endif
