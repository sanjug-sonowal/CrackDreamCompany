// Last updated: 18/10/2025, 09:01:35
class Solution {
public:
    vector<int> res;
    int size;
    
    bool backtrack(vector<int>& res, vector<bool>& used, int pos, int n) {
        if (pos == size) return true;  // Successfully filled the sequence
        
        if (res[pos] != 0)  // Skip already filled positions
            return backtrack(res, used, pos + 1, n);
        
        // Try placing numbers from n to 1
        for (int i = n; i >= 1; i--) {
            if (used[i]) continue;  // Skip used numbers
            
            if (i == 1) { // Place '1' at a single position
                res[pos] = 1;
                used[i] = true;
                if (backtrack(res, used, pos + 1, n)) return true;
                used[i] = false;
                res[pos] = 0;
            } else {  // Place 'i' at two positions (pos and pos + i)
                if (pos + i < size && res[pos + i] == 0) {
                    res[pos] = res[pos + i] = i;
                    used[i] = true;
                    if (backtrack(res, used, pos + 1, n)) return true;
                    used[i] = false;
                    res[pos] = res[pos + i] = 0;
                }
            }
        }
        
        return false;  // No valid placement found, backtrack
    }
    
    vector<int> constructDistancedSequence(int n) {
        size = 2 * n - 1;
        res.assign(size, 0);
        vector<bool> used(n + 1, false);
        backtrack(res, used, 0, n);
        return res;
    }
};
