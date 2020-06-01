#include "dyntab.h"
#include <stdlib.h>
#include <string.h>

Dyntab dtcreate(int size, int len, int cap) {
	Dyntab tab = NULL;
	tab = malloc(sizeof(Sdyntab));
	
	// If malloc fail for structure alloc, stoping execution and returning NULL
	if (tab == NULL) {
		return NULL;
	}

	tab->len = len;
	tab->size = size;

	// If len > cap, then cap = len
	if (len > cap) {
		tab->cap = len;
	} else {
		tab->cap = cap;
	}

	tab->data = NULL;

	// If len > 0, then allocate the memory and set all the bytes to 0
	if (len > 0) {
		tab->data = malloc(tab->size * tab->cap);

		// If this allocation fail, then free the already allocated memory for the structure and return NULL
		if (tab->data == NULL) {
			free(tab);
			return NULL;
		}

		// set all bytes to 0
		memset(tab->data, 0, tab->size * tab->len);
	}

	return tab;
}

int dtappend(Dyntab tab, void* element) {
	// If data is at maximum capacity, extending the capacity
	// In a normal case, len is never greater than cap
	if (tab->len >= tab->cap) {
		void* tmp = NULL;
		tmp = realloc(tab->data, tab->cap * tab->size * 2); // Double the current capacity

		if (tmp == NULL) {
			return 1;
		}

		// if success then update the memory zone and the capacity
		tab->data = tmp;
		tab->cap *= 2;
	}

	// copy the data
	// a cast to char* is necessary as void* cannot deal with pointer arithmetic. As char* equals a byte, we can move at the precise byte
	// of the data array, which is : addr of data + len * size (number of bytes of each element)
	memcpy(((char*)tab->data) + tab->len * tab->size, element, tab->size);
	tab->len++;

	return 0;
}

void dtdel(Dyntab tab) {
	free(tab->data);
	free(tab);
}