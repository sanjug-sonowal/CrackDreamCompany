// Last updated: 18/10/2025, 09:02:33
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        int n = words.size();
        
        // Iterate through each word in the array
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break; // No need to check further, already found as a substring
                }
            }
        }
        
        return result;
    }
};
