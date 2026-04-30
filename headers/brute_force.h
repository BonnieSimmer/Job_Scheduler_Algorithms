//
// Created by bonniesimmer on 4/30/26.
//

#ifndef TASK_7_BRUTE_FORCE_H
#define TASK_7_BRUTE_FORCE_H

#include "algorithm.h"

class BruteForce : public Algorithm {
public:
    ll schedule(const vector<Job> &jobs) override;

private:
    static void solve_recursive(const vector<Job> &jobs, vector<bool> &used,
                                int jobs_scheduled, long long current_time,
                                long long current_penalty, long long &min_penalty);
};

#endif //TASK_7_BRUTE_FORCE_H
