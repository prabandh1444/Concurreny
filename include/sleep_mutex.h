#include <iostream>
#include <atomic>


class SleepMutex
{
private:
    std::atomic<bool> flag_;

public:

    SleepMutex() : flag_() {}
    SleepMutex(const SleepMutex& other) = delete;
    SleepMutex(SleepMutex&& other) = delete;
    SleepMutex& operator=(const SleepMutex& other) = delete;
    SleepMutex& operator=(SleepMutex&& other) = delete;
 
    void lock();
    void unlock();
    void try_lock();
    
    ~SleepMutex(){}

};