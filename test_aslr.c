#include "types.h"
#include "user.h"
#include "stat.h"

int global_var = 0;

int main(void) {
  int stack_var = 1;

  printf(1, "Location of stack variable: %p\n", (void*)&stack_var);

  exit();
}
