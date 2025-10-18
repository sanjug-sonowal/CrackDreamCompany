// Last updated: 18/10/2025, 09:08:18
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>arrWithIndex;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            arrWithIndex.push_back({nums[i],i});
        }

        sort(arrWithIndex.begin(),arrWithIndex.end());

        int left = 0; int right = arrWithIndex.size() - 1;

        while(left < right){
            int sum = arrWithIndex[left].first + arrWithIndex[right].first;
            if(sum == target){
                return {arrWithIndex[left].second,arrWithIndex[right].second};
            }else if(sum < target){
                left++;
            }else{
                right--;
            }
        }

        return {-1,-1};
    }
};