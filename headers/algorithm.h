//
// Created by bonniesimmer on 4/30/26.
//

#ifndef TASK_7_ALGORITHM_H
#define TASK_7_ALGORITHM_H
#include <vector>

#define ll long long

using namespace std;

struct Job {
    int processing_time;
    int deadline;
    int penalty;
};

class Algorithm {
    public:
    virtual ~Algorithm() = default;

    virtual ll schedule(const std::vector<Job>& jobs) = 0;
};

#endif //TASK_7_ALGORITHM_H
