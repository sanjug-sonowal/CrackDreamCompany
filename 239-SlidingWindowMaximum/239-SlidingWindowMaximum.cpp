// Last updated: 18/10/2025, 09:06:25
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q; // store indices
        vector<int> ans;

        int start = 0, end = 0;

        while (end < n) {
            // Maintain decreasing order in deque
            while (!q.empty() && nums[q.back()] < nums[end]) {
                q.pop_back();
            }
            q.push_back(end);

            // Remove elements out of current window
            if (q.front() < start) {
                q.pop_front();
            }

            // When window size hits k
            if (end - start + 1 == k) {
                ans.push_back(nums[q.front()]);
                start++;  // slide window
            }

            end++;
        }
        return ans;
    }
};
