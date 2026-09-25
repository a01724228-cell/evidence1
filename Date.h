#include <iostream>
using namespace std;
#include <string>

class Date {
private:
    int month;
    int day;
    int hour;
    int minute;
    int second;

    int monthInt(const string& monthStr) {
        if (monthStr == "Jan") {
            return 1;
        }
        else if (monthStr == "Feb") {
            return 2;
        }
        else if (monthStr == "Mar") {
            return 3;
        }
        else if (monthStr == "Apr") {
            return 4;
        }
        else if (monthStr == "May") {
            return 5;
        }
        else if (monthStr == "Jun") {
            return 6;
        }
        else if (monthStr == "Jul") {
            return 7;
        }
        else if (monthStr == "Aug") {
            return 8;
        }
        else if (monthStr == "Sep") {
            return 9;
        }
        else if (monthStr == "Oct") {
            return 10;
        }
        else if (monthStr == "Nov") {
            return 11;
        }
        else if (monthStr == "Dec") {
            return 12;
        }
        return 0;
    }

public:

    Date() {
        month = 0;
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
    }

    Date(const string& m, int d, int hr, int min, int sec) {
        month = monthInt(m);
        day = d;
        hour = hr;
        minute = min;
        second = sec;
    }

    int beforeAfter(const Date& otherDate) {
        if (month != otherDate.month) {
            if (month < otherDate.month) {
                return -1;
            }
            else if (month > otherDate.month) {
                return 1;
            }
        }
        if (day != otherDate.day) {
            if (day < otherDate.day) {
                return -1;
            }
            else if (day > otherDate.day) {
                return 1;
            }
        }
        if (hour != otherDate.hour) {
            if (hour < otherDate.hour) {
                return -1;
            }
            else if (hour > otherDate.hour) {
                return 1;
            }
        }
        if (minute != otherDate.minute) {
            if (minute < otherDate.minute) {
                return -1;
            }
            else if (minute > otherDate.minute) {
                return 1;
            }
        }
        if (second != otherDate.second) {
            if (second < otherDate.second) {
                return -1;
            }
            else if (second > otherDate.second) {
                return 1;
            }
        }
        return 0;
    }
};
