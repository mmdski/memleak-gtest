#include <stdlib.h>
void *p;
int
memory_double_free() {
  p = malloc(7);
  free(p);
  free(p);
  return 0;
}
