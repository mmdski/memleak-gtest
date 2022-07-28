#include <stdlib.h>
void *p;
int
memory_leak() {
  p = malloc(7);
  p = 0; // The memory is leaked here.
  return 0;
}
