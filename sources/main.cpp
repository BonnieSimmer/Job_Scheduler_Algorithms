#include <iostream>
#include <vector>
#include <climits>
#include "../headers/brute_force.h"
#include "../headers/divide_and_conquer.h"
#include "../headers/dynamic_programming.h"

#define ll long long

using namespace std;

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

    BruteForce brute_force;
    cout << "Brute force minimum penalty: " << brute_force.schedule(jobs) << "\n";

    DivideAndConquer conquer;
    cout << "Divide and conquer minimum penalty: " << conquer.schedule(jobs) << "\n";

    DynamicProgramming dynamic_programming;
    cout << "Dynamic programming minimum penalty: " << dynamic_programming.schedule(jobs) << "\n";

    return 0;
}