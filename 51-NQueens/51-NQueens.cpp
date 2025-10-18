// Last updated: 18/10/2025, 09:07:39
class Solution {
public:

    void find(int row,int n,vector<vector<string>>&ans,vector<string>&Board,vector<bool>&column,vector<bool>&leftDiag,vector<bool>&rightDiag){
        //base case
        if(row == n){
            ans.push_back(Board);
            return;
        }

        // put the qweens to its correct place
        for(int j = 0;j<n;j++){
            if(column[j] == 0 && leftDiag[(n - 1) + j - row] == 0 && rightDiag[row + j] == 0){
                column[j] = 1;
                Board[row][j] = 'Q';
                leftDiag[n-1 + j - row] = 1;
                rightDiag[row + j] = 1;
                find(row + 1,n,ans,Board,column,leftDiag,rightDiag);
                column[j] = 0;
                Board[row][j] = '.';
                leftDiag[n-1 + j - row] = 0;
                rightDiag[row + j] = 0;
            }
        } 
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>Board(n);
        vector<bool>column(n,0);

        vector<bool>leftDiag(2*n-1,0);
        vector<bool>rightDiag(2*n-1,0);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                Board[i].push_back('.');
            }
        }

        find(0,n,ans,Board,column,leftDiag,rightDiag);

        return ans;
    }
};