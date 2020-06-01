#include <stdio.h>
#include <stdlib.h>
#include "dyntab.h"

int main(void) {
	Dyntab t = dtcreate(sizeof(int), 8, 16);

	/*
	printf("size : %d\n", t->size);
	printf("len : %d\n", t->len);
	printf("cap : %d\n", t->cap);

	printf("addr : %d\n", t);
	printf("data addr : %d\n", &t->data);
	printf("len addr : %d\n", &t->len);
	printf("cap addr : %d\n", &t->cap);
	printf("size addr : %d\n", &t->size);
	*/

	for (int i = 0; i < t->cap; i++) {
		printf("t[%d] = %d\n", i, ((int*)t->data)[i]);
	}

	int addvar = 5;

	dtappend(t, &addvar);
	dtappend(t, &addvar);
	dtappend(t, &addvar);
	dtappend(t, &addvar);
	dtappend(t, &addvar);
	dtappend(t, &addvar);
	dtappend(t, &addvar);
	dtappend(t, &addvar);
	dtappend(t, &addvar);

	printf("Cap = %d\n", t->cap);

	for (int i = 0; i < t->cap; i++) {
		printf("t[%d] = %d\n", i, ((int*)t->data)[i]);
	}

	dtdel(t);

	return 0;
}