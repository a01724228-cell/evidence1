#include <iostream>
using namespace std;
#include "Date.h"
#include "SortedLog.h"
#include <fstream>
#include <vector>

void files (const string& inputFileStr, const string& outputFileStr) {
    ifstream inputFile(inputFileStr);
    ofstream outputFile(outputFileStr);
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening the files" << endl;
        return;
    }

    vector<SortedLog> logs;
    string monthStr;
    int day, hr, min, sec;
    char colon1, colon2;

    while (inputFile >> monthStr >> day >> hr >> colon1 >> min >> colon2 >> sec) {
        string line;
        getline(inputFile, line);

        string complete = monthStr + " " + to_string(day) + " " + to_string(hr) + ":" + to_string(min) + ":" + to_string(sec) + " " + line;

        Date date(monthStr, day, hr, min, sec);
        logs.push_back(SortedLog(date, complete));
    }
    inputFile.close();

    SortedLog logSort;
    logSort.sortLog(logs);

    vector <SortedLog> sorted = logSort.getData();

    for (int i = 0; i < sorted.size(); i++) {
        outputFile << sorted[i].getDataLine() << endl;
    }
    outputFile.close();
}


int main() {

    return 0;
}
