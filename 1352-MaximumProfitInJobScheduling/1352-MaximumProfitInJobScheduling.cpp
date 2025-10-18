// Last updated: 18/10/2025, 09:03:14
class Solution {
public:

struct Job {
    int start, finish, profit;
};

int binarySearch(vector<Job>& jobs, int index) {
    int low = 0, high = index - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (jobs[mid].finish <= jobs[index].start) {
            if (jobs[mid + 1].finish <= jobs[index].start)
                low = mid + 1;
            else
                return mid;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<Job> jobs(n);

    // Populate the jobs vector
    for (int i = 0; i < n; i++) {
        jobs[i] = {startTime[i], endTime[i], profit[i]};
    }

    // Sort jobs based on their finish times using a lambda function
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.finish < b.finish;
    });

    // Initialize an array to store the maximum profit for each job
    vector<int> dp(n, 0);
    dp[0] = jobs[0].profit;

    // Fill the dp array
    for (int i = 1; i < n; i++) {
        int inclProf = jobs[i].profit;
        int l = binarySearch(jobs, i);
        if (l != -1) {
            inclProf += dp[l];
        }
        dp[i] = max(inclProf, dp[i - 1]);
    }

    // Return the maximum profit
    return dp[n - 1];
}
};