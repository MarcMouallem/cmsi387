#include <stdio.h>
#include <unistd.h>

int main() {
    int result = syscall(201); // time
    // JD: Would it really have been that hard to add a little explanatory text
    //     or even do some basic conversions here, to make the output more
    //     usable for human beings?
    printf("%d\n", result);
    return 0;
}
