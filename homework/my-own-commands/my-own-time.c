#include <stdio.h>
#include <unistd.h>

int main() {
    int result = syscall(201); // time
    printf("%d\n", result);
    return 0;
}
