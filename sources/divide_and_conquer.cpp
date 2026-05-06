#include "../headers/divide_and_conquer.h"
#include <climits>

// Merge Sort
void merge(vector<Job>& jobs, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<Job> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = jobs[l + i];
    for (int j = 0; j < n2; j++) R[j] = jobs[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        // Sort by deadline o
        if (L[i].deadline <= R[j].deadline) {
            jobs[k] = L[i];
            i++;
        } else {
            jobs[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) jobs[k++] = L[i++];
    while (j < n2) jobs[k++] = R[j++];
}

void mergeSort(vector<Job>& jobs, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(jobs, l, m);
        mergeSort(jobs, m + 1, r);
        merge(jobs, l, m, r);
    }
}

ll DivideAndConquer::solve_recursive(vector<Job>& jobs, int start, int end, ll current_time) {
    ll min_total_penalty = LLONG_MAX;
    //  Only one job left
    if (start == end) {
        ll finish_time = current_time + jobs[start].processing_time;
        return (finish_time > jobs[start].deadline) ? jobs[start].penalty : 0;
    }
    for (int i = start; i <= end; i++) {

        Job temp = jobs[start];
        jobs[start] = jobs[i];
        jobs[i] = temp;

        // Calculate penalty
        ll finish_time = current_time + jobs[start].processing_time;
        ll current_job_penalty = (finish_time > jobs[start].deadline) ? jobs[start].penalty : 0;

        //Recursively solve for the remaining jobs
        ll remaining_penalty = solve_recursive(jobs, start + 1, end, finish_time);

        // Keep track of the minimum penalty
        if (current_job_penalty + remaining_penalty < min_total_penalty) {
            min_total_penalty = current_job_penalty + remaining_penalty;
        }
        temp = jobs[start];
        jobs[start] = jobs[i];
        jobs[i] = temp;
    }
    return min_total_penalty;
}

ll DivideAndConquer::schedule(const vector<Job>& jobs) {
    if (jobs.empty()) return 0;
    vector<Job> jobs_copy = jobs;
    return solve_recursive(jobs_copy, 0, jobs_copy.size() - 1, 0);
}