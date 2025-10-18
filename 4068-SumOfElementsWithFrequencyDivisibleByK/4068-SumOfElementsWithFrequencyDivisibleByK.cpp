// Last updated: 18/10/2025, 08:58:45
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        int totalSum = 0;

        for (int num : nums) {
            frequencyMap[num]++;
        }

        for (const auto& [element, frequency] : frequencyMap) {
            if (frequency % k == 0) {
                totalSum += element * frequency;
            }
        }
        
        return totalSum;
    }
};