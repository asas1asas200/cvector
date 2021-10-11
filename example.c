#include <stdio.h>
#include "cvector.h"

void print_vector(struct Vector* v) {
	printf("v->size = %d\n", v->size);
	printf("v->capacity = %d\n", v->capacity);
	for(int i=0;i<v->size;++i)
		printf("v[%d] = %d\n", i, *(int *)v->at(v, i));
}

int main(void) {
	struct Vector* v = NULL;
	init_vector(&v);
	for(int i=0;i<10;i++) {
		int* a = malloc(sizeof(int));
		*a = i;
		v->push_back(v, a);
	}
	print_vector(v);

	v->pop_back(v);
	v->pop_back(v);
	v->pop_back(v);
	v->pop_back(v);
	v->pop_back(v);
	puts("After pop 5 elements: ");
	print_vector(v);

	
	v->clear(v);
	puts("After clear vector: ");
	print_vector(v);
}
