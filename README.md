# CVector

A vector implementation by C.

## Basic Usage

Like `std::vector` in C++ STL, but there is some differents:

1. Not like `std::vector`, it can store any type element by this implementation.
2. Due to some reasons, it don't have `resize()` method, more info in [this commit](https://github.com/asas1asas200/cvector/commit/d38f6b22d9ffbe09b98bd23c53cc96f622b56300)
3. When you want to get the value of one element, you must cast the pointer type and then dereference it.

```c
#include <stdio.h>
#include <stdlib.h>

#include "cvector.h"

int main(void) {
	struct Vector* v = NULL;

	init_vector(&v);
	v->push_back(v, malloc(sizeof(int)));
	v->push_back(v, malloc(sizeof(int)));
	v->push_back(v, malloc(sizeof(int)));
	*(int *)v->at(v, 0) = 10;
	*(int *)v->at(v, 1) = 20;
	*(int *)v->at(v, 2) = 30;

	printf("v->size = %d\n", v->size);
	for(int i=0;i<v->size;++i)
		printf("v[%d] = %d\n", i, *(int *)v->at(v, i));

	v->clear(v);
	printf("v->size = %d\n", v->size);

	return 0;
}
```

More operations in `example.c`.
