#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

char buf[512];
bool haveeol = false;
size_t n;

int main(void) {
    while((n = read(0, buf, sizeof(buf)))) {
        if (haveeol) { putchar('\n'); }
        if (buf[n-1] == '\n') {
            haveeol = true;
            n -= 1;
        }
        write(1, buf, n);
    }
}
