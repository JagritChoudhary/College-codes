
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Process {
    int id;
    int arrivaltime;
    int bursttime;
    int completiontime;
    int turnaroundtime;
    int waitingtime;
};

// Compare function based on arrival time
bool compareArrival(Process a, Process b) {
    return a.arrivaltime < b.arrivaltime;
}

// SJF Scheduling function
void FindSJF(Process Proc[], int n) {
    sort(Proc, Proc + n, compareArrival); // Sort by arrival time first
    vector<bool> isCompleted(n, false); // Track completed processes
    int currenttime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int idx = -1; // Index of the shortest job
        int minBurstTime = INT_MAX;

        // Find the process with the smallest burst time among the arrived processes
        for (int i = 0; i < n; i++) {
            if (Proc[i].arrivaltime <= currenttime && !isCompleted[i]) {
                if (Proc[i].bursttime < minBurstTime) {
                    minBurstTime = Proc[i].bursttime;
                    idx = i;
                }
            }
        }

        // If no process is ready to execute, advance time
        if (idx == -1) {
            currenttime++;
        } else {
            // Process the selected index
            Proc[idx].completiontime = currenttime + Proc[idx].bursttime;
            Proc[idx].turnaroundtime = Proc[idx].completiontime - Proc[idx].arrivaltime;
            Proc[idx].waitingtime = Proc[idx].turnaroundtime - Proc[idx].bursttime;

            currenttime = Proc[idx].completiontime; // Move current time to completion of selected process
            isCompleted[idx] = true; // Mark this process as completed
            completedProcesses++; // Increment completed process count
        }
    }
}


void printable(Process Proc[], int n) {
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "p" << Proc[i].id << "\t";
        cout << Proc[i].arrivaltime << "\t" << Proc[i].bursttime << "\t"
             << Proc[i].completiontime << "\t"
             << Proc[i].turnaroundtime << "\t"
             << Proc[i].waitingtime << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process Proc[n];

    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        Proc[i].id = i + 1;
        cin >> Proc[i].arrivaltime >> Proc[i].bursttime;
    }

    FindSJF(Proc, n);
    printable(Proc, n);

    return 0;
}
