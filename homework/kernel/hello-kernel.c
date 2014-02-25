#include "unistd.h"
#include "sys/syscall.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	int i = syscall(314, argv[1]);
 	return 0;
}
