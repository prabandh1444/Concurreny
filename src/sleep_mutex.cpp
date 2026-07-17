#include <sleep_mutex.h>
#include <common.h>
#include <linux/futex.h>
#include <sys/syscall.h>
#include <unistd.h>

void SleepMutex::lock()
{
    while(xchg((unsigned char*)&flag_, 1)!=0) syscall(SYS_futex, &flag_, FUTEX_WAIT, 1);
}

void SleepMutex::unlock()
{
    flag_ = 0;
    syscall(SYS_futex, &flag_, FUTEX_WAKE, 0);
}

void SleepMutex::try_lock()
{
    xchg((unsigned char*)&flag_, 1);
}
