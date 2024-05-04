#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "help.h"

int main(int argc, char** argv) {
        if (argc == 1) {
                printf((const char*) help_txt, *argv, *argv);
                exit(0);
        }

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
