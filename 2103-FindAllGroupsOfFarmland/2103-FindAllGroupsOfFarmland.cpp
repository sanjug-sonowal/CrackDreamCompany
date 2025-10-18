// Last updated: 18/10/2025, 09:01:01
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> result;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 1) {
                    int r1 = i, c1 = j, r2 = i, c2 = j;
                    dfs(land, i, j, r1, c1, r2, c2);
                    result.push_back({r1, c1, r2, c2});
                }
            }
        }
        
        return result;
    }
    
    void dfs(vector<vector<int>>& land, int i, int j, int& r1, int& c1, int& r2, int& c2) {
        if (i < 0 || j < 0 || i >= land.size() || j >= land[0].size() || land[i][j] != 1) return;
        
        land[i][j] = 0; // mark visited
        
        r2 = max(r2, i);
        c2 = max(c2, j);
        
        dfs(land, i + 1, j, r1, c1, r2, c2); // down
        dfs(land, i - 1, j, r1, c1, r2, c2); // up
        dfs(land, i, j + 1, r1, c1, r2, c2); // right
        dfs(land, i, j - 1, r1, c1, r2, c2); // left
        
        r1 = min(r1, i);
        c1 = min(c1, j);
    }
};
