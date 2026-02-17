// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	va_list valist;
	va_start(valist, flags);

	int ret = syscall(__NR_open, filename, flags, valist);

	va_end(valist);

	if(ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
