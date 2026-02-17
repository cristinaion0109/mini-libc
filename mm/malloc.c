// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

	mem_list_add(p, size);

	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	void *p = mmap(NULL, size * nmemb, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

	mem_list_add(p, size * nmemb);

	return p;
}

void free(void *ptr)
{
	struct mem_list* aux = mem_list_find(ptr);

	munmap(ptr, aux->len);
	mem_list_del(aux->start);
}

void *realloc(void *ptr, size_t size)
{
	struct mem_list* aux = mem_list_find(ptr);

	aux->start = mremap(aux->start, aux->len, size, 0);

	return aux->start;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	struct mem_list* aux = mem_list_find(ptr);

	aux->start = mremap(aux->start, aux->len, size * nmemb, 0);

	return aux->start;
}
