// Last updated: 18/10/2025, 08:59:49
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int eleSum =0;
        int digitSum = 0;

        for(int x : nums){
            eleSum += x;
            int tempans = x;
            while(tempans != 0){
                digitSum += tempans % 10;
                tempans /= 10;
            }
        }

        return eleSum - digitSum;
    }
};