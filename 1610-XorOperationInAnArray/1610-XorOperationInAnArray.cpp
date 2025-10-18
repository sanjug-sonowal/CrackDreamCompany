// Last updated: 18/10/2025, 09:02:15
class Solution {
public:
    int xorOperation(int n, int start) {
        int xorans = 0;
        vector<int>res(n);
        for(int i = 0; i< n; i++){
            res[i] = start + 2 * i;
            xorans ^= res[i];
        }
        return xorans;
    }
};