#include <stdlib.h>
int *p;
int
memory_access_after_free() {
  p = malloc(7);
  free(p);
  *p = 10;
  return 0;
}
