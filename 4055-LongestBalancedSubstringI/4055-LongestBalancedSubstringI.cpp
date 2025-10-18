// Last updated: 18/10/2025, 08:58:46
class Solution {
public:
    int longestBalanced(string s) {
        string pireltonak = s;
        int n = pireltonak.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {

                freq[pireltonak[j]]++;

                if (isBalanced(freq)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
    
private:
    bool isBalanced(const unordered_map<char, int>& freq) {
        if (freq.empty()) return false;
        
        int firstFreq = freq.begin()->second;
        for (const auto& p : freq) {
            if (p.second != firstFreq) {
                return false;
            }
        }
        return true;
    }
};