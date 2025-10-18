// Last updated: 18/10/2025, 08:59:42
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // Define vowels for quick lookup
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        // Create a prefix sum array
        int n = words.size();
        vector<int> prefix(n, 0);
        
        // Populate the prefix sum array
        for (int i = 0; i < n; ++i) {
            bool startsWithVowel = vowels.count(words[i][0]);
            bool endsWithVowel = vowels.count(words[i].back());
            prefix[i] = (startsWithVowel && endsWithVowel) ? 1 : 0;
            if (i > 0) {
                prefix[i] += prefix[i - 1];
            }
        }
        
        // Answer each query using the prefix sum
        vector<int> result;
        for (const auto& query : queries) {
            int li = query[0], ri = query[1];
            int count = prefix[ri] - (li > 0 ? prefix[li - 1] : 0);
            result.push_back(count);
        }
        
        return result;
    }
};
