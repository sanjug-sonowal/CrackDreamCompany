// Last updated: 18/10/2025, 09:06:21
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 1)
        return true;

        for(int i = 0; i < n;i++){
            for(int j = i + 1;j < n; j++){
                if(intervals[i][1] > intervals[j][0] && intervals[j][1] > intervals[i][0])
                return false;
            }
        }
        return true;
    }
};