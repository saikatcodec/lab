#include <bits/stdc++.h>
using namespace std;

struct process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

bool cmp(process &a, process &b) { return a.at < b.at; }
bool cmpQ(process &a, process &b) { return a.bt < b.bt; }

int main() {
    int n;
    cin >> n;

    vector<process> pros(n);
    for (int i = 0; i < n; i++) {
        cin >> pros[i].at >> pros[i].bt;
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
    cout << setw(textWidth) << "ID" << setw(textWidth) << "AT"
         << setw(textWidth) << "BT" << setw(textWidth) << "CT"
         << setw(textWidth) << "BT" << setw(textWidth) << "TAT"
         << setw(textWidth) << "WT" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(textWidth) << resultQ[i].id << setw(textWidth)
             << resultQ[i].at << setw(textWidth) << resultQ[i].bt
             << setw(textWidth) << resultQ[i].ct << setw(textWidth)
             << resultQ[i].tat << setw(textWidth) << resultQ[i].wt << endl;
    }

    return 0;
}
