#include <stdlib.h>
#include <stdio.h>
#include "status_code.h"

struct Vector{
	size_t capacity;
	size_t size;
	void** array;
	ssize_t (*reserve)(struct Vector*, size_t);
	ssize_t (*push_back)(struct Vector*, void*);
	ssize_t (*pop_back)(struct Vector*);
	void* (*at)(struct Vector*, size_t);
};

ssize_t reserve(struct Vector* self, size_t new_capacity) {
	void** new_array = malloc(new_capacity * sizeof(void*));
	self->capacity = new_capacity;

	if(!self->array)
		goto skip_free;

	for(size_t idx = 0, min_capacity = new_capacity < self->capacity ? new_capacity : self->capacity
		; idx < min_capacity ; ++idx) {
		if(self->array[idx]) {
			new_array[idx] = self->array[idx];
		} else {
			break;
		}
	}

	free(self->array);
skip_free:
	self->array = new_array;
	return SUCCESS;
}

ssize_t push_back(struct Vector* self, void* element) {
	if(!element)
		return NULL_POINTER_ERROR;

	if(self->size==self->capacity)
		self->reserve(self, self->capacity<<1);
	self->array[self->size++] = element;
}

void* at(struct Vector* self, size_t idx) {
	if(idx>=self->size) {
		fprintf(stderr, "Index out of bounds.\n");
		abort();
	}
	return self->array[idx];
}

void init_vector(struct Vector** v) {
	*v = malloc(sizeof(struct Vector));
	(*v)->reserve = reserve;
	(*v)->push_back = push_back;
	(*v)->at = at;
	(*v)->size = 0;
	(*v)->reserve(*v, 2);
}

