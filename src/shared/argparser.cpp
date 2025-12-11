#include "argparser.h"

Args::Args(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == 'n' && argv[i][1] == 'e') {
                this->execute = false;
            } else if (argv[i][1] == 'h') {
                this->help = true;
            }
        }
    }
}