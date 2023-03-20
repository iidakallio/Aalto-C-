// copy your implementation from the last round here (if you had one and used it)
// and wrap it inside a WeirdMemoryAllocator namespace

#ifndef AALTO_ELEC_CPP_COUNTER_CLASS
#define AALTO_ELEC_CPP_COUNTER_CLASS
const int max_refcount = 3;

// implement a reference counter helper class if you want to

namespace WeirdMemoryAllocator {
    class RestrictedRefCounter{
    public:

        RestrictedRefCounter() : ref_count_(1) {
        }
        RestrictedRefCounter(const RestrictedRefCounter&) = delete;
        RestrictedRefCounter& operator=(const RestrictedRefCounter&) = delete;
        
        ~RestrictedRefCounter() {}

        int GetCount(){
            return ref_count_;
        }
    bool Increase() {
            if(ref_count_ <= max_refcount) {
                ref_count_++;
                return true;
            }
            return false;
        }
        void Decrease(){
            ref_count_--;
        }

    private:
        int ref_count_;


    };
};
#endif
