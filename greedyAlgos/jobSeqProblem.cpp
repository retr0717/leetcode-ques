#include <bits/stdc++.h>
using namespace std;

struct Jobs {
  int id;
  int deadline;
  int profit;
};

bool comparator(struct Jobs job1, struct Jobs job2) {
  return job1.profit > job2.profit;
}

vector<int> jobScheduling(vector<vector<int>> &jobs) {
  vector<struct Jobs> JobsArr;
  int totProfit = 0, maxDeadline = 0;
  int n = jobs.size();
  int count = 0;

  for (int i = 0; i < n; i++) {
    JobsArr.push_back({jobs[i][0], jobs[i][1], jobs[i][2]});
    maxDeadline = max(jobs[i][1], maxDeadline);
  }

  sort(JobsArr.begin(), JobsArr.end(), comparator);

  vector<int> hashMap(maxDeadline + 1, -1);

  for (int i = 0; i < n; i++) {
    for (int j = JobsArr[i].deadline; j > 0; j--) {
      if (hashMap[j] == -1) {
        count++;
        hashMap[j] = JobsArr[i].id;
        totProfit += JobsArr[i].profit;
        break;
      }
    }
  }

  return {count, totProfit};
}
