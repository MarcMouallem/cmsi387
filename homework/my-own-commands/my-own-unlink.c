#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int result = syscall(87, argv[1]); // unlink pathname
    printf("%d\n", result);
    return 0;
}
