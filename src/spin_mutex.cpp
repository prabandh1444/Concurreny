#include <spin_mutex.h>
#include <common.h>

void SpinMutex::lock()
{
    while(xchg((unsigned char*)&flag_, 1)!=0) ;
}

void SpinMutex::unlock()
{
    flag_ = 0;
}

void SpinMutex::try_lock()
{
    xchg((unsigned char*)&flag_, 1);
}
