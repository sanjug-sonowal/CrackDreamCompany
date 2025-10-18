// Last updated: 18/10/2025, 09:00:59
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";
        
        for (int i = 0; i < n; i++) {
            // Flip the diagonal element
            result += (nums[i][i] == '0') ? '1' : '0';
        }
        
        return result;
    }
};
