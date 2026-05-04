//
// Created by bonniesimmer on 4/30/26.
//

#ifndef TASK_7_DYNAMIC_PROGRAMMING_H
#define TASK_7_DYNAMIC_PROGRAMMING_H

#include "algorithm.h"

class DynamicProgramming : public Algorithm {
    public:
    ll schedule(const vector<Job>& jobs) override;
};

#endif //TASK_7_DYNAMIC_PROGRAMMING_H
