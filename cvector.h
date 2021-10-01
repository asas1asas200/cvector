#include <stdlib.h>
#include "status_code.h"

struct Vector{
	void* begin;
	void* end;
	size_t capacity;
	size_t size;
	void** array;
	ssize_t (*reserve)(struct Vector*, size_t);
	void (*resize)(struct Vector*, size_t);
	ssize_t (*push_back)(struct Vector*, void*);
	void* (*at)(struct Vector*, size_t);
};
