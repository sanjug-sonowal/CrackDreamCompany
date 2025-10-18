// Last updated: 18/10/2025, 09:01:33
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int count = 0;
        int max = INT_MIN;

         for(int i = 0; i < rectangles.size();i++){
                    int square = min(rectangles[i][0], rectangles[i][1]);
                    if(square == max) count++;
                    if(square > max){
                         max = square;
                         count = 1;
                    }
               
          }
        return count;
    }
};