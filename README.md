# dyntab
Dynamic arrays for C, based on Go's slice system

```c
int dtappend(int size, int len, int cap);
int dtappend(Dyntab tab, void* element);
void dtdel(Dyntab tab);
void* dtget(Dyntab tab, int index);
```
