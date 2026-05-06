//
// Created by bonniesimmer on 4/30/26.
//

#ifndef TASK_7_DIVIDE_AND_CONQUER_H
#define TASK_7_DIVIDE_AND_CONQUER_H

#include <vector>
#include "algorithm.h"

class DivideAndConquer: public Algorithm {
    public:
    ll schedule(const vector<Job> &jobs) override;
    private:
    ll solve_recursive(vector<Job> &jobs, int start, int end, long long current_time);
    void merge(vector<Job>& jobs, int l, int m, int r);
    void merge_sort(vector<Job>& jobs, int l, int r);


};

#endif //TASK_7_DIVIDE_AND_CONQUER_H
