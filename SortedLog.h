#include <vector>
#include "Date.h"
#include <string>
using namespace std;

class SortedLog {
private:
    Date date;
    string dataLine;
    vector<SortedLog> logs;

    int compare(const SortedLog& otherDate) {
        return date.beforeAfter(otherDate.date);
    }

    void merge(vector<SortedLog>& A, int l, int m, int r) {
        int s1 = m-l+1;
        int s2 = r-m;
        vector<SortedLog> L(s1);
        vector<SortedLog> R(s2);
        for (int i = 0; i < s1; i++) {
            L[i] = A[l+i];
        }
        for (int j = 0; j < s2; j++) {
            R[j] = A[m+j+1];
        }
        int i = 0;
        int j = 0;
        int k = l;
        while (i<s1 && j<s2) {
            if (L[i].compare(R[j]) <= 0) {
                A[k] = L[i];
                i++;
            }
            else {
                A[k] = R[j];
                j++;
            }
            k++;
        }
        while (i<s1) {
            A[k] = L[i];
            i++;
            k++;
        }
        while (j<s2) {
            A[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<SortedLog>& A, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            mergeSort(A, l, mid);
            mergeSort(A, mid + 1, r);
            merge(A, l, mid, r);
        }
    }

public:

    SortedLog() {
        date = Date();
        dataLine = " ";
        logs = vector<SortedLog>();
    }

    SortedLog(Date d, string line) {
        date = d;
        dataLine = line;
    }

    void sortLog(const vector<SortedLog>& unsorted) {
        logs = unsorted;

        if (!logs.empty()) {
            mergeSort(logs, 0, logs.size() - 1);
        }
    }

    vector<SortedLog> getData() {
        return logs;
    }

    string getDataLine() {
        return dataLine;
    }
};
