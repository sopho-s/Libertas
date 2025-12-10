#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#pragma once

class Cron {
    private:
        std::string maincron;
        std::vector<std::string> cronlines;
        std::string shell;
        void ClearComments();
    public:
        Cron();
};