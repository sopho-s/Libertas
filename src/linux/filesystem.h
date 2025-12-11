#include <string>
#include <sstream>
#include <unistd.h>
#include "exec.h"
#pragma once

class File {
    private:
        std::string path;
        std::string absolutepath;
        bool isabsolute;
        bool usercanwrite;
        bool usercanread;
        bool usercanexecute;
        bool exists;
        void GetAbsolute();
        void CheckExists();
        void CheckPerms();
    public:
        File(std::string path);
        bool IsAbsolute() {return this->isabsolute;}
        bool UserCanWrite() {return this->usercanwrite;}
        bool UserCanRead() {return this->usercanread;}
        bool UserCanExecute() {return this->usercanexecute;}
        std::string ReturnPath() {return this->path;}
        std::string ReturnAbsolute() {return this->absolutepath;}
};