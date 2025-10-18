// Last updated: 18/10/2025, 09:01:26
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
           if (s1 == s2) return true; // Already equal
        
        vector<int> diffIndices;
        
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                diffIndices.push_back(i);
            }
        }
        
        if (diffIndices.size() != 2) return false;
        
        int i1 = diffIndices[0], i2 = diffIndices[1];
        
    
        swap(s1[i1], s1[i2]);
        
        return s1 == s2;
    }
};