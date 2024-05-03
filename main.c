#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
        if (setuid(0)) {
                fprintf(stderr, "Couldn't set UID\n");
                exit(1);
        };

        if (setgid(0)) {
                fprintf(stderr, "Couldn't set GID\n");
                exit(1);
        }

        argv++;
        execvp(argv[0], argv);
}
