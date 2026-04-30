#include "../headers/brute_force.h"
#include <algorithm>
#include <climits>

ll BruteForce::schedule(const vector<Job> &jobs) {
    vector<bool> used(jobs.size(), false);
    ll min_penalty = LLONG_MAX;
    
    solve_recursive(jobs, used, 0, 0, 0, min_penalty);
    
    return min_penalty;
}

void BruteForce::solve_recursive(const vector<Job> &jobs, vector<bool> &used,
                                 int jobs_scheduled, ll current_time, 
                                 ll current_penalty, ll &min_penalty) {
    if (current_penalty >= min_penalty) {
        return; 
    }

    // Base case: all jobs have been scheduled
    if (jobs_scheduled == jobs.size()) {
        min_penalty = min(min_penalty, current_penalty);
        return;
    }

    // Try every job for the current position
    for (int i = 0; i < jobs.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            
            ll next_time = current_time + jobs[i].processing_time;
            ll next_penalty = current_penalty;
            
            if (next_time > jobs[i].deadline) {
                next_penalty += jobs[i].penalty;
            }
            solve_recursive(jobs, used, jobs_scheduled + 1, next_time, next_penalty, min_penalty);

            used[i] = false;
        }
    }
}