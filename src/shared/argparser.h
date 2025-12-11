#include <iostream>
#pragma once

class Args {
    public:
        bool execute = true;
        bool help = false;
        Args(int argc, char *argv[]);
};