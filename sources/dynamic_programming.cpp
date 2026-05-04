//
// Created by bonniesimmer on 4/30/26.
//

#include "../headers/dynamic_programming.h"
#include <algorithm>
#include <climits>

ll DynamicProgramming::schedule(const vector<Job>& jobs) {
    const int n = jobs.size();
    if (n == 0) return 0;

    const int total_states = 1 << n;
    
    vector<ll> penalty(total_states, LLONG_MAX);
    vector<ll> time(total_states, 0);

    // Calculate the total time for every possible subset of jobs
    for (int i = 0; i < total_states; i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { //check if job j in state i
                time[i] += jobs[j].processing_time;
            }
        }
    }

    // Base case: 0 penalty for completing 0 jobs
    penalty[0] = 0;

    for (int i = 1; i < total_states; i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                // the state before job j was added
                int prev_job = i ^ (1 << j);
                
                if (penalty[prev_job] != LLONG_MAX) {
                    ll penalty_for_i = 0;
                    
                    if (time[i] > jobs[j].deadline) {
                        penalty_for_i = jobs[j].penalty;
                    }
                    penalty[i] = min(penalty[i], penalty[prev_job] + penalty_for_i);
                }
            }
        }
    }
    //the state where all jobs are completed
    return penalty[total_states - 1];
}
