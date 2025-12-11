#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "filesystem.h"
#include "../shared/toolpage.h"
#pragma once

class CronLine {
    public:
        std::string minute;
        std::string hour;
        std::string day;
        std::string month;
        std::string weekday;
        std::string user;
        CronLine() {;}
        void SetIndex(std::string value, int index) {
            switch (index) {
                case 0:
                    this->minute = value;
                    return;
                case 1:
                    this->hour = value;
                    return;
                case 2:
                    this->day = value;
                    return;
                case 3:
                    this->month = value;
                    return;
                case 4:
                    this->weekday = value;
                    return;
                case 5:
                    this->user = value;
                    return;
            }
        }
        std::string ToString() {return this->minute + " " + this->hour + " " + this->day + " " + this->month + " " + this->weekday + "\t" + this->user;}
};

class Cron {
    private:
        std::string maincron;
        std::vector<std::pair<CronLine, std::string>> cronlines;
        std::string shell;
        void ClearComments();
        void GetLines();
        void UnifyWhitespace();
    public:
        Cron();
        std::string ToString() {
            std::string returnstring = "";
            for (std::pair<CronLine, std::string> cronline : cronlines) {
                returnstring += cronline.first.ToString() + " " + cronline.second + "\n";
            }
            return returnstring.substr(0, returnstring.size() - 1);
        }
        std::vector<std::string> ReturnLines() {
            std::vector<std::string> returnstrings;
            for (std::pair<CronLine, std::string> line : this->cronlines) {
                returnstrings.push_back(line.first.ToString() + "\t" + line.second);
            }
            return returnstrings;
        }
        std::vector<File> GetAllFiles();
};