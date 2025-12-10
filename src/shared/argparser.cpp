#include "argparser.h"

Args::Args(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (argv[i] == "-ne") {
            this->execute = false;
        }
    }
}