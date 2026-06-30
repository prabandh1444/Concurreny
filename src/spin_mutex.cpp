#include <spin_mutex.h>

void SpinMutex::lock()
{
    __asm__ __volatile__(
    "start:\n\t"
    "movb $1, %%al\n\t"
    "xchgb %%al, %0\n\t"
    "cmpb $0, %%al\n\t"
    "jne start\n\t"
    : "+m"(flag_)
    :
    : "%al", "memory"
    );
}

void SpinMutex::unlock()
{
    flag_ = 0;
}

void SpinMutex::try_lock()
{
    __asm__ __volatile__(
    "movb $1, %%al\n\t"
    "xchgb %%al, %0\n\t"
    "ret"
    : "+m"(flag_)
    :
    : "%al", "memory"
    );
}
