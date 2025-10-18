// Last updated: 18/10/2025, 09:04:47
class Solution {
public:
    bool dfs(int node, int currentColor, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = currentColor;
        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - currentColor, color, graph)) 
                    return false;
            } else if (color[neighbor] == currentColor) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph))
                    return false;
            }
        }
        return true;
    }
};