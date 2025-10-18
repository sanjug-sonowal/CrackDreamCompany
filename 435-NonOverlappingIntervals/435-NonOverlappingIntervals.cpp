// Last updated: 18/10/2025, 09:05:46
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
         sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int lEnd = intervals[0][1];

        for(int i = 1;i<intervals.size();i++){
            if(intervals[i][0] < lEnd){
                count++;
            }else{
                lEnd = intervals[i][1];
            }
        }
        return count;
    }
};