// Last updated: 18/10/2025, 09:08:13
class Solution {
public:
    double merge(vector<int>nums1,vector<int>nums2){
        vector<int>ans;
        int i = 0;
        int j = 0;
        int k = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
            k++;
        }

        while(i < nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }


        int n = ans.size();
        if (n % 2 == 1) return ans[n/2];
        else return (ans[n/2 - 1] + ans[n/2]) / 2.0;

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = merge(nums1,nums2);
        return median;
    }
};