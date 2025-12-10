#include "cron.h"

void Cron::ClearComments() {
    std::string tempstring = "";
    bool incomment = false;
    bool hashadletter = false;
    for (char letter : this->maincron ) {
        if (letter == '\n') {
            if (hashadletter) {
                tempstring += letter;
            }
            incomment = false;
            hashadletter = false;
        } else if (letter == '#') {
            incomment = true;
        } else if (!incomment) {
            tempstring += letter;
            hashadletter = true;
        }
    }
    this->maincron = tempstring;
}

Cron::Cron() {
    std::ifstream cronfile("/etc/crontab");
    std::string crontext = "";
    std::string line = "";
    while(getline(cronfile, line)) {
        crontext += line + "\n";
    }
    cronfile.close();
    this->maincron = crontext;
    this->ClearComments();
    std::cout << this->maincron << std::endl;
}