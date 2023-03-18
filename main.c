#include <signal.h>
#include <stdio.h>
#include "edge-lib.h"

#include <stdlib.h>

unsigned count = 0;
int loop = 1;

void sigusr1Handler(int signum) {
  printf("sigusr1 received.\n");
  count = 1000;
  loop = 0;
}

void sigusr2Handler(int signum) {
  printf("sigusr2 received.\n");
  count = 100000;
  loop = 0;
}

void sigintHandler(int signum) {
  printf("Interrupt signal received. exit\n");
  exit(0);
}

void process() {
  do {
    if (loop) {
      // do nothing
    } else {
      do_it(count);
      loop = 1;
    }
  } while (1);
}

int main(int argc, char *argv[]) {
  signal(SIGUSR1, sigusr1Handler);
  signal(SIGUSR2, sigusr2Handler);
  signal(SIGINT, sigintHandler);

  process();

  return 0;
}
