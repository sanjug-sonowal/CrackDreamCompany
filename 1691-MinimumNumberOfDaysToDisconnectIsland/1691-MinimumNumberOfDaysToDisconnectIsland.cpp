// Last updated: 18/10/2025, 09:01:59
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Helper function to count the number of islands
        auto countIslands = [&](vector<vector<int>>& g) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            int islands = 0;
            
            auto dfs = [&](int x, int y, auto&& dfs) -> void {
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || g[x][y] == 0)
                    return;
                visited[x][y] = true;
                dfs(x + 1, y, dfs);
                dfs(x - 1, y, dfs);
                dfs(x, y + 1, dfs);
                dfs(x, y - 1, dfs);
            };
            
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1 && !visited[i][j]) {
                        islands++;
                        dfs(i, j, dfs);
                    }
                }
            }
            
            return islands;
        };
        
        // If the grid is already disconnected, return 0
        if (countIslands(grid) != 1) return 0;
        
        // Try removing one cell at a time and check if the grid gets disconnected
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1) return 1;
                    grid[i][j] = 1; // revert the change
                }
            }
        }
        
        // If removing one cell doesn't disconnect, it requires at least 2 days
        return 2;
    }
};
