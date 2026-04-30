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
};

#endif //TASK_7_DIVIDE_AND_CONQUER_H
