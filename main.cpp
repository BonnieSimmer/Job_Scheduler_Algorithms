#include <iostream>
#include <vector>
#include <climits>

#define ll long long

using namespace std;

struct Job {
    int processing_time;
    int deadline;
    int penalty;
};

void brute_force_algorithm(vector<Job>& jobs, vector<bool>& used, vector<int>& current_order,ll& min_penalty) {
    // All jobs have been added to the current sequence
    if (current_order.size() == jobs.size()) {
        ll current_total_penalty = 0;
        ll current_time = 0;

        for (int index : current_order) {
            current_time += jobs[index].processing_time;
            if (current_time > jobs[index].deadline) {
                current_total_penalty += jobs[index].penalty;
            }
        }

        if (current_total_penalty < min_penalty) {
            min_penalty = current_total_penalty;
        }
        return;
    }

    // Try every job for the current position
    for (int i = 0; i < jobs.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            current_order.push_back(i);

            brute_force_algorithm(jobs, used, current_order, min_penalty);

            // Remove the job and mark it as unused for the next branch
            current_order.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int number_of_jobs;
    cin >> number_of_jobs;
    if (number_of_jobs == 0) return 0;

    vector<Job> jobs(number_of_jobs);
    for (int i = 0; i < number_of_jobs; i++) {
        cin >> jobs[i].processing_time;
        cin >> jobs[i].deadline;
        cin >> jobs[i].penalty;
    }

    vector<bool> used(number_of_jobs, false);
    vector<int> current_order;
    ll min_penalty = LLONG_MAX;

    brute_force_algorithm(jobs, used, current_order, min_penalty);

    cout << min_penalty << endl;

    return 0;
}