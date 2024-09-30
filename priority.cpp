#include <bits/stdc++.h>
using namespace std;

struct process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int priority;
};

bool cmp(process &a, process &b) { return a.at < b.at; }
bool cmpQ(process &a, process &b) { return a.priority < b.priority; }

int main() {
    int n;
    cout << "Enter process no: ";
    cin >> n;

    vector<process> pros(n);
    for (int i = 0; i < n; i++) {
        cout << "For process  " << i + 1 << " arrival, brust and priority: ";
        cin >> pros[i].at >> pros[i].bt >> pros[i].priority;
        pros[i].id = i + 1;
    }

    sort(pros.begin(), pros.end(), cmp);

    vector<process> readyQ, resultQ;

    int currentTime = 0;

    while (!pros.empty() || !readyQ.empty()) {
        while (!pros.empty() && pros[0].at <= currentTime) {
            readyQ.push_back(pros[0]);
            pros.erase(pros.begin());
        }

        sort(readyQ.begin(), readyQ.end(), cmpQ);

        if (!readyQ.empty()) {
            process currntPros = readyQ[0];
            readyQ.erase(readyQ.begin());
            int start = max(currentTime, currntPros.at);
            currntPros.ct = start + currntPros.bt;
            currntPros.tat = currntPros.ct - currntPros.at;
            currntPros.wt = currntPros.tat - currntPros.bt;
            currentTime = currntPros.ct;
            resultQ.push_back(currntPros);
        } else {
            currentTime = pros[0].at;
        }
    }

    int textWidth = 10;
    cout << "ID" << "\t\t" << "AT"
         << "\t\t" << "BT" << "\t\t" << "CT"
         << "\t\t" << "TAT" << "\t\t" << "WT" << endl;
    for (int i = 0; i < n; i++) {
        cout << resultQ[i].id << "\t\t" << resultQ[i].at << "\t\t"
             << resultQ[i].bt << "\t\t" << resultQ[i].ct << "\t\t"
             << resultQ[i].tat << "\t\t" << resultQ[i].wt << endl;
    }

    return 0;
}
