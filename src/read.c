#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *buffer;
    while (1) {
        read(1, &buffer, 1);
        printf("%c\n", buffer);
    }
}




