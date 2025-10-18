// Last updated: 18/10/2025, 09:02:59
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>result(n,0);
        int i = 0;
        int j = n - 1;
        int start = 1;
        while(i < j){
            result[i] = start;
            result[j] = -start;
            start++;

            i++;
            j--;
        }
        return result;
    }
};