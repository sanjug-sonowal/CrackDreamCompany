// Last updated: 18/10/2025, 09:03:04
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int r,c;
          int count = 0;
          //step 1 = init array with 0's
          vector<vector<int>> mat(m,vector<int>(n,0));

          //step 2 take r of i and c of i to iterate and increament
          for(int i = 0;i<indices.size();i++){
               r = indices[i][0];
               c = indices[i][1];

                   //step 3 = increament by 1 rows
          for(int j = 0; j< n;j++){
               mat[r][j] += 1;
          }
          

          //step 4 = increament by 1 colomns
          for(int k = 0;k < m;k++){
               mat[k][c] += 1;
          }
          }

      

          //step 5 = count the odd numbers
          for(int i = 0;i<m;i++){
               for(int j = 0; j<n;j++){
                    cout<<mat[i][j];
                    if(mat[i][j] % 2 == 1){
                         count++;
                    }
               }
          }

          return count;

    }
};