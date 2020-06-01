#ifndef LP_DYNTAB
#define LP_DYNTAB

// represents a dyntab
struct lp_dyntab {
	void* data;
	int len;
	int cap;
	int size;
};

// define current name usage dyntab as a pointer to a dyntab struct, to make usage more easy
typedef struct lp_dyntab *Dyntab;

// define current name of the structure itself
typedef struct lp_dyntab Sdyntab;

/**
 * allocate all the memory and initialize it correctly.
 * size = the size of elements of the tab
 * len = the initial number of elements of the tab, will be initialized with 0 value
 * cap = capacity of the tab = size preallocated in memory for append, to avoid a realloc syscall each time a call to append is made
 */
Dyntab dtcreate(int size, int len, int cap);

// Append an element at the end of the dyntab, increasing the capcity if necessary
int dtappend(Dyntab tab, void* element);

// Free all the space that the dyntab uses
void dtdel(Dyntab tab);

// Return the address of a specific item of the data array, or NULL if it doesn't exists
void* dtget(Dyntab tab, int index);

#endif