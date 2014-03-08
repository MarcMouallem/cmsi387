#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int result = syscall(86, argv[1], argv[2]); // link oldpath newpath
    // JD: OK when debugging, but in final form better to just return the result.
    printf("%d\n", result);
    return 0;
}
