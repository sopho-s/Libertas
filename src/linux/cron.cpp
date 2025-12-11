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

void Cron::UnifyWhitespace() {
    std::string tempstr = "";
    bool hashadwhitespace = false;
    bool hashadnewline = false;
    for (char letter : this->maincron ) {
        if (letter != '\n') {
            if (letter == '\t') {
                letter = ' ';
            }
            if (letter == ' ') {
                if (~hashadwhitespace) {
                    hashadwhitespace = true;
                    tempstr += ' ';
                }
            } else {
                hashadwhitespace = false;
                tempstr += letter;
            }
        } else {
            if (~hashadnewline) {
                hashadnewline = true;
                tempstr += "\n";
            }
        }
    }
    this->maincron = tempstr;
}

void Cron::GetLines() {
    
    std::istringstream iss(this->maincron);

    for (std::string line; std::getline(iss, line); )
    {
        if (line.substr(0, 5) == "SHELL") {
            this->shell = line.substr(6, line.size() - 6);
        } else {
            std::string tempstr = line;
            CronLine cronline = CronLine();
            for (int i = 0; i < 5; i++) {
                std::string time = tempstr.substr(0, tempstr.find(' '));
                tempstr = tempstr.substr(tempstr.find(' ') + 1);
                cronline.SetIndex(time, i);
            }
            this->cronlines.push_back({cronline, tempstr});
        }
    }
}

Cron::Cron() {
    DisplayInfo("Analysing cron");
    std::ifstream cronfile("/etc/crontab");
    std::string crontext = "";
    std::string line = "";
    while(getline(cronfile, line)) {
        crontext += line + "\n";
    }
    cronfile.close();
    this->maincron = crontext;
    this->ClearComments();
    this->UnifyWhitespace();
    this->GetLines();
    DisplayInfo("Nothing found with cron");
}