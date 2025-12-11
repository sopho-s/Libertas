#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "filesystem.h"
#include "../shared/toolpage.h"
#pragma once

class CronLine {
    private:
        std::string minute;
        std::string hour;
        std::string day;
        std::string month;
        std::string weekday;
    public:
        CronLine() {;}
        void SetMinute(std::string minute) {this->minute = minute;}
        void SetHour(std::string hour) {this->hour = hour;}
        void SetDay(std::string day) {this->day = day;}
        void SetMonth(std::string month) {this->month = month;}
        void SetWeekday(std::string weekday) {this->weekday = weekday;}
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
                default:
                    return;
            }
        }
        std::string ToString() {return this->minute + " " + this->hour + " " + this->day + " " + this->month + " " + this->weekday;}
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
        std::vector<File> GetAllFiles();
};