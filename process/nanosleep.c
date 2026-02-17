#include <time.h>
#include <internal/syscall.h>
#include <stdlib.h>
#include <errno.h>

int nanosleep(struct timespec *t1, struct timespec *t2)
{
    return syscall(__NR_nanosleep, t1, t2);
}
