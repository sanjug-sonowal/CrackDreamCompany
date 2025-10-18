// Last updated: 18/10/2025, 09:01:05
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // Arrays to store first and last occurrence of each character
        vector<int> first(26, -1), last(26, -1);
        
        // Fill first and last occurrences
        for (int i = 0; i < s.size(); ++i) {
            int index = s[i] - 'a';
            if (first[index] == -1) {
                first[index] = i;  // First occurrence
            }
            last[index] = i;  // Last occurrence (updates as we traverse)
        }
        
        int result = 0;
        
        // Iterate over all characters from 'a' to 'z'
        for (int i = 0; i < 26; ++i) {
            if (first[i] != -1 && last[i] != -1 && first[i] < last[i]) {
                // Use a set to find unique characters between first[i] and last[i]
                unordered_set<char> uniqueMiddle;
                for (int j = first[i] + 1; j < last[i]; ++j) {
                    uniqueMiddle.insert(s[j]);
                }
                result += uniqueMiddle.size();  // Add count of unique middle characters
            }
        }
        
        return result;
    }
};
