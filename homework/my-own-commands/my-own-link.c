#include <stdio.h>
#include "unistd.h"
#include "sys/syscall.h"

int main(int argc, char *argv[]) {
    int result = syscall(86, argv[1], argv[2]); // link oldpath newpath
    printf("%d\n", result);
    return 0;
}
