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

// allocates the memory, and initialize the dyntab struct
Dyntab dtcreate(int size, int len, int cap);
int dtappend(Dyntab tab, void* element);

#endif