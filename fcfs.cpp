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

int main() {
    int n;
    cin >> n;

    process pros[n];
    for (int i = 0; i < n; i++) {
        cin >> pros[i].at >> pros[i].bt;
        pros[i].id = i + 1;
    }

    sort(pros, pros + n, cmp);

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        int start = max(currentTime, pros[i].at);
        pros[i].ct = pros[i].bt + start;
        pros[i].tat = pros[i].ct - pros[i].at;
        pros[i].wt = pros[i].tat - pros[i].bt;
        currentTime = pros[i].ct;
    }

    cout << setw(5) << "ID" << setw(5) << "AT" << setw(5) << "BT" << setw(5)
         << "CT" << setw(5) << "BT" << setw(5) << "TAT" << setw(5) << "WT"
         << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(5) << pros[i].id << setw(5) << pros[i].at << setw(5)
             << pros[i].bt << setw(5) << pros[i].ct << setw(5) << pros[i].tat
             << setw(5) << pros[i].wt << endl;
    }

    return 0;
}
