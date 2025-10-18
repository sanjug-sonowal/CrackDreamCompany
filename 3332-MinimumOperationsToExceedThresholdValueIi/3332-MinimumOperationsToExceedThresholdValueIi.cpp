// Last updated: 18/10/2025, 08:59:03
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
          std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap(nums.begin(), nums.end());
        int operations = 0;

        while (minHeap.size() > 1 && minHeap.top() < k) {
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();

            long long newVal = x * 2 + y; // Use long long to prevent overflow
            minHeap.push(newVal);
            operations++;
        }

        return operations;
    }
};