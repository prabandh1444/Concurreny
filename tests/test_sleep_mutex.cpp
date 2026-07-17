#include <thread>
#include <vector>
#include <cassert>

#include <sleep_mutex.h>

SleepMutex m;
size_t counter = 0;
size_t NUM_THREADS = 20;

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
    auto start_time = std::chrono::system_clock::now();
    for(size_t i=0; i<NUM_THREADS; i++) threads.emplace_back(worker);
    for(auto &thread : threads) thread.join();
    auto end_time = std::chrono::system_clock::now();
    auto time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout<<"Time taken is "<< (time_taken/1e3) << std::endl;
    assert(counter == NUM_THREADS*1000000);
}