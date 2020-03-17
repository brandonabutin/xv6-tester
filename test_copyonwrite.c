#include "types.h"
#include "user.h"
#include "stat.h"

int main(void) {
  printf(1, "Number of initial free pages: %d\n", getfreepages());
  int data = 1;
  int pid;

  printf(1, "Number of free pages after initializing variables: %d\n", getfreepages());

  pid = fork();
  if(pid == 0) {
    printf(1, "Number of free pages in child before changing data: %d\n", getfreepages());
    data = 2;
    printf(1, "Number of free pages in child after changing data: %d\n", getfreepages());
    pid = fork();
    if(pid == 0) {
      printf(1, "Number of free pages in nested child before changing data: %d\n", getfreepages());
      data = 3;
      printf(1, "Number of free pages in nested child after changing data: %d\n", getfreepages());
    } else {
      wait();
      printf(1, "Number of free pages in child after wait: %d\n", getfreepages());
    }
  } else {
    wait();
    printf(1, "Number of free pages in parent after wait: %d\n", getfreepages());
    pid = fork();
    if(pid == 0) {
      printf(1, "Number of free pages in child2 before changing data: %d\n", getfreepages());
      data = 4;
      printf(1, "Number of free pages in child2 after changing data: %d\n", getfreepages());
    } else {
      wait();
      printf(1, "Number of free pages in parent after wait: %d\n", getfreepages());
    }
  }

  (void)data;

  exit();
}
