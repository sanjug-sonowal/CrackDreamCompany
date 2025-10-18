// Last updated: 18/10/2025, 09:03:40
class Solution {
public:
    int dfs(vector<int>& freq) {
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) { 
                count++;  // Count this sequence
                freq[i]--; // Use this letter
                count += dfs(freq); // Recursively generate more sequences
                freq[i]++; // Backtrack
            }
        }
        return count;
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for (char c : tiles) {
            freq[c - 'A']++; // Count frequency of each character
        }
        return dfs(freq);
    }
};
