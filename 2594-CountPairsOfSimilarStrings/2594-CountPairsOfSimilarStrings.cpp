// Last updated: 18/10/2025, 08:59:52
class Solution {
public:
    int similarPairs(vector<string>& words) {
     unordered_map<int, int> maskCount;
        
        // Step 1: Create mask for each word and count them
        for (auto &word : words) {
            int mask = 0;
            for (char c : word) {
                mask |= (1 << (c - 'a'));
            }
            maskCount[mask]++;
        }

        // Step 2: Count pairs using nC2 = k*(k-1)/2
        int count = 0;
        for (auto &entry : maskCount) {
            int k = entry.second;
            count += (k * (k - 1)) / 2;
        }

        return count;
    }
};