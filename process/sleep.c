#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>

unsigned int sleep(unsigned int s)
{
    struct timespec t = {s, 0};

	nanosleep(&t, NULL);

    return 0;
}
