#include <thread>
#include <vector>
#include <cassert>

#include <spin_mutex.h>

SpinMutex m;
size_t counter = 0;

void worker()
{
    for(size_t i=0;i<1000000; i++)
    {
        m.lock();
        counter++;
        m.unlock();
    }
}


int main()
{
    std::vector<std::thread> threads;
    for(size_t i=0; i<8; i++) threads.emplace_back(worker);
    for(auto &thread : threads) thread.join();
    assert(counter == 8*1000000);
}