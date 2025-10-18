// Last updated: 18/10/2025, 09:03:09
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
         std::unordered_map<int, int> productCount;
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        for (auto& [product, count] : productCount) {
            if (count > 1) {
                result += (count * (count - 1) / 2) * 8;
            }
        }

        return result;
    }
};