// Last updated: 18/10/2025, 09:00:33
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(int x:nums){
            freq[x]++;
        }

        for(auto &p:freq){
            if(p.second % 2 != 0)
            return false;
        }

        return true;
    }
};