#include <stdlib.h>
void *p;
int
memory_no_leak() {
  p = malloc(7);
  free(p);
  return 0;
}
