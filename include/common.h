static inline unsigned char xchg(unsigned char* p, unsigned char v) 
{
    asm volatile(
        "xchgb %0, %1"
        : "+q"(v), "+m"(*p)
        :
        : "memory"
    );
    return v;
}