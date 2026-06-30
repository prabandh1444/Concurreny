#include <iostream>

class SpinMutex
{
private:
    bool flag_;

public:

    SpinMutex() {}
    SpinMutex(const SpinMutex& other) = delete;
    SpinMutex(SpinMutex&& other) = delete;
    SpinMutex& operator=(const SpinMutex& other) = delete;
    SpinMutex& operator=(SpinMutex&& other) = delete;
 
    void lock();
    void unlock();
    void try_lock();
    
    ~SpinMutex(){}
};
