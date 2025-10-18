// Last updated: 18/10/2025, 08:58:51
class Solution {
private:
    int manhattanDist(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    
    bool canPartition(vector<vector<int>>& points, int minDist) {
        int n = points.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (manhattanDist(points[i], points[j]) < minDist) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    
                    for (int v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 2) return 0;

        set<int> distances;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                distances.insert(manhattanDist(points[i], points[j]));
            }
        }
        
        vector<int> dists(distances.begin(), distances.end());

        int left = 0, right = dists.size() - 1;
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPartition(points, dists[mid])) {
                result = dists[mid];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};