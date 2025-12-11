#include "filesystem.h"

void File::GetAbsolute() {
    std::string commandstring = "find / -name *" + this->path;
    char* charpath = new char[commandstring.size()];
    for (int i = 0; i < commandstring.size(); i++) {
        charpath[i] = commandstring[i];
    }
    const char* constcharpath = charpath;
    std::string result = exec(constcharpath);
    std::istringstream iss(result);
    std::string line;
    std::getline(iss, result);
    if (line != "") {
        this->absolutepath = line;
        this->exists = true;
    } else {
        this->exists = false;
        this->absolutepath = "";
    }
}

void File::CheckPerms() {
    char* charpath = new char[this->absolutepath.size()];
    for (int i = 0; i < this->absolutepath.size(); i++) {
        charpath[i] = this->absolutepath[i];
    }
    const char* constcharpath = charpath;
    if (access(constcharpath, R_OK) == 0) {
        this->usercanread = true;
    }
    if (access(constcharpath, W_OK) == 0) {
        this->usercanwrite = true;
    }
    if (access(constcharpath, X_OK) == 0) {
        this->usercanexecute = true;
    }
}

File::File(std::string path) {
    this->path = path;
    if (this->path[0] != '/') {
        this->isabsolute = false;
        this->GetAbsolute();
    } else {
        this->absolutepath = path;
        this->isabsolute = true;
    }
    this->CheckPerms();
}