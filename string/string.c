// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *aux = destination;

	while (*source != '\0') {
		*aux = *source;
		aux++;
		source++;
	}

	*aux = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *aux = destination;

	for (size_t i = 0; i < len; i++) {
		if (*source != '\0') {
			*(aux + i) = *(source + i);
		} else {
			*(aux + i) = '\0';
		}
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *aux = destination;

	while (*aux != '\0') {
		aux++;
	}

	while (*source != '\0') {
		*aux = *source;
		aux++;
		source++;
	}

	*aux = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *aux = destination;

	while (*aux != '\0') {
		aux++;
	}

	for (size_t i = 0; i < len; i++) {
		if(*source != '\0') {
			*aux = *source;
			aux++;
			source++;
		} else {
			*aux = '\0';
		}
	}

	*aux = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	char *copy1 = (char *)str1;
	char *copy2 = (char *)str2;

	while (*copy1 != '\0' && *copy2 != '\0') {
		if (*copy1 > *copy2) {
			return 1;
		} else if (*copy1 < *copy2) {
			return -1;
		}
		copy1++;
		copy2++;
	}

	if (*copy1 == '\0' && *copy2 != '\0') {
        return -1;
    }

    if (*copy1 != '\0' && *copy2 == '\0') {
        return 1;
    }

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++) {
		if (*str1 != '\0' && *str2 != '\0') {
			if (*str1 > *str2) {
				return 1;
			} else if (*str1 < *str2) {
				return -1;
			}
			str1++;
			str2++;
		} else {
			break;
		}
	}

	if (i < len) {
		if (*str1 == '\0' && *str2 != '\0') {
			return -1;
		}
		if (*str1 != '\0' && *str2 == '\0') {
			return 1;
		}
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	char *aux = (char *)str;

	while (*aux != '\0') {
		if (*aux == c) {
			return aux;
		}
		aux++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *aux = NULL;
	char *copy = (char *)str;

	while (*copy != '\0') {
		if (*copy == c) {
			aux = copy;
		}
		copy++;
	}

	return aux;
}

char *strstr(const char *haystack, const char *needle)
{
	char *copy_haystack = (char *)haystack;
    char *copy_needle = (char *)needle;

    while (*haystack != '\0') {
        if (*copy_haystack != *copy_needle) {
			if (*copy_needle == '\0') {
				return (char *)haystack;
			}
			haystack++;
            copy_haystack = (char *)haystack;
            copy_needle = (char *)needle;
        } else {
            copy_haystack++;
            copy_needle++;
        }
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *copy_haystack = (char *)haystack;
    char *copy_needle = (char *)needle;
	char *aux = NULL;

	 while (*haystack != '\0') {
        if (*copy_haystack != *copy_needle) {
			if (*copy_needle == '\0') {
				aux = (char *)haystack;
			}
			haystack++;
            copy_haystack = (char *)haystack;
            copy_needle = (char *)needle;
        } else {
            copy_haystack++;
            copy_needle++;
        }
    }

	return aux;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dst = (char *)destination;
	const char *src = (const char *)source;

	for (size_t i = 0; i < num; i++) {
		*(dst + i) = *(src + i);
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dst = (char *)destination;
	char *src = (char *) source;

	for (size_t i = 0; i < num; i++) {
		*(dst + i) = *(src + i);
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *aux1 = (char *)ptr1;
	char *aux2 = (char *)ptr2;

	size_t i;
	for (i = 0; i < num; i++) {
		if (*aux1 != '\0' && *aux2 != '\0') {
			if (*aux1 > *aux2) {
				return 1;
			} else if (*aux1 < *aux2) {
				return -1;
			}
			aux1++;
			aux2++;
		} else {
			break;
		}
	}

	if (i < num) {
		if (*aux1 == '\0' && *aux2 != '\0') {
			return -1;
		}
		if (*aux1 != '\0' && *aux2 == '\0') {
			return 1;
		}
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *src = (char *)source;
	char val = (char)value;

	for (size_t i = 0; i < num; i++) {
		*(src + i) = val;
	}

	return source;
}
