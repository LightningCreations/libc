#include <unistd.h>

int main(int argc, char *argv[]) {
    write(0, "Hello, world!\n", 14);
}
