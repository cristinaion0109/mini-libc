#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../include/internal/io.h"

int puts(char* str)
{
    write(1, str, strlen(str));
    write(1, "\n", 1);

    return 0;
}
