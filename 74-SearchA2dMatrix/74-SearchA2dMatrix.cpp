// Last updated: 18/10/2025, 09:07:27
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size(),M = matrix[0].size();
        int start = 0,end = N*M - 1,row_index,col_index,mid;

        while(start <= end)
        {
            mid = (start + end)/2;
            row_index = mid / M;
            col_index = mid % M;

            if(matrix[row_index][col_index] == target)
            {
                return 1;
            }else if(matrix[row_index][col_index] < target)
            {
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return 0;
    }
};