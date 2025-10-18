// Last updated: 18/10/2025, 08:59:10
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
          int n = nums.size();
    int xorResult = 0;
    int result = 0;

    for (int num : nums) {
        xorResult ^= num;
    }

    for (int i = 30; i >= 0; --i) {
        int mask = 1 << i;
        int xorBit = (xorResult & mask) != 0;
        int kBit = (k & mask) != 0;

        if (xorBit == 1 && kBit == 0) {
            result++;
        } else if (xorBit == 0 && kBit == 1) {
            result++;
            xorResult |= mask;
        }
    }

    return result;
    }
};