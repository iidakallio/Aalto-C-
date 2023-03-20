#ifndef AALTO_ELEC_CPP_COUNTER_CLASS
#define AALTO_ELEC_CPP_COUNTER_CLASS

// implement a reference counter helper class if you want to

class RestrictedRefCounter{
public:

    RestrictedRefCounter() : ref_count_(0) {
    }
    RestrictedRefCounter(const RestrictedRefCounter&) = delete;
    RestrictedRefCounter& operator=(const RestrictedRefCounter&) = delete;
    
    ~RestrictedRefCounter() {}

    int GetCount(){
        return ref_count_;
    }
    void Increase(){
        ref_count_++;
    }

    void Decrease(){
        ref_count_--;
    }

private:
    int ref_count_;


};

#endif