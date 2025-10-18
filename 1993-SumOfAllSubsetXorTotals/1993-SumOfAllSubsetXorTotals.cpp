// Last updated: 18/10/2025, 09:01:14
class Solution {
public:
int dfs(int i, int curr, const vector<int>& nums) {
    if (i == nums.size()) return curr;
    // Include nums[i] in the current XOR
    int take = dfs(i + 1, curr ^ nums[i], nums);
    // Exclude nums[i] (don't change current XOR)
    int noTake = dfs(i + 1, curr, nums);
    return take + noTake;
}
    int subsetXORSum(vector<int>& nums) {
         int n = nums.size();
    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int x = 0;
        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j)) x ^= nums[j];
        }
        ans += x;
    }
    cout << ans << endl; // Output: 28 for [5, 1, 6]
    return ans;
    }
};