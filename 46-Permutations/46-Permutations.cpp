// Last updated: 18/10/2025, 09:07:44
class Solution {
public:

    void permute(vector<int>arr,vector<vector<int>>&ans,int index)
    {
        if(arr.size() == index)
        {
            ans.push_back(arr);
            return;
        }

        for(int i = index; i < arr.size();i++)
        {
            swap(arr[index],arr[i]);
            permute(arr,ans,index+1);
            swap(arr[index],arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;

        permute(nums,ans,0);

        return ans;
    }
};