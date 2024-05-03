#include <unistd.h>

int main(int argc, char** argv) {
        setuid(0);
        setgid(0);

        ++(*argv);
        execvp(argv[0], argv);
}
