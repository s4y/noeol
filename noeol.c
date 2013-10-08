#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    char buf[1024];
    bool haveeol = false;
    size_t n;
    while((n = read(0, buf, sizeof(buf)))) {
        if (haveeol) { putchar('\n'); }
        if (buf[n-1] == '\n') {
            haveeol = true;
            n -= 1;
        }
        write(1, buf, n);
    }
}
