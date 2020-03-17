#include "types.h"
#include "user.h"
#include "stat.h"

int global_var = 0;

int main(void) {
  int stack_var = 1;
  int *heap_var = malloc(5);

  printf(1, "Location of stack variable: %p\n", (void*)&stack_var);
  printf(1, "Location of heap variable: %p\n", (void*)&heap_var);
  printf(1, "Location of global variable: %p\n", (void*)&global_var);

  free(heap_var);

  return 0;
}
