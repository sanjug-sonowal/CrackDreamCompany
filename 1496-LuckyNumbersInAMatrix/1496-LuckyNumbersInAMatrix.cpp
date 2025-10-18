// Last updated: 18/10/2025, 09:02:42
class Solution {
public:
  vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckyNumbers;
        
        // Step 1: Find the minimum element in each row
        for (int i = 0; i < matrix.size(); ++i) {
            int minElement = matrix[i][0];
            int minIndex = 0;
            
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                    minIndex = j;
                }
            }
            
            // Step 2: Check if this minimum element is the maximum in its column
            bool isMaxInColumn = true;
            for (int k = 0; k < matrix.size(); ++k) {
                if (matrix[k][minIndex] > minElement) {
                    isMaxInColumn = false;
                    break;
                }
            }
            
            // Step 3: If it is, add it to the list of lucky numbers
            if (isMaxInColumn) {
                luckyNumbers.push_back(minElement);
            }
        }
        
        return luckyNumbers;
    }
};