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

ssize_t reserve(struct Vector* self, size_t new_capacity) {
	void** new_array = malloc(new_capacity * sizeof(void*));
	self->capacity = new_capacity;
	if(!self->array) {
		self->array = new_array;
		return SUCCESS;
	}

	for(size_t idx = 0, max_capacity = new_capacity > self->capacity ? new_capacity : self->capacity
		; idx < max_capacity ; ++idx) {
		if(self->array[idx]) {
			new_array[idx] = self->array[idx];
		} else {
			break;
		}
	}
	free(self->array);
	return SUCCESS;
}
