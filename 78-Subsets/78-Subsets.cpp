// Last updated: 18/10/2025, 09:07:23
class Solution {
public:
    void subseq(vector<int> arr,int index,int n,vector<vector<int>>& ans,vector<int>temp){
        if(index == n){
            ans.push_back(temp);
            return;
        }

        //if no
        subseq(arr,index + 1,n,ans,temp);

        //if yes
        temp.push_back(arr[index]);
        subseq(arr,index + 1,n,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        subseq(nums,0,nums.size(),ans,temp);
        return ans;
    }
};