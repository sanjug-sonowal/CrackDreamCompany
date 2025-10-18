// Last updated: 18/10/2025, 08:58:54
class Solution {
public:
    long long getSquareFreePart(long long num) {
        long long result = 1;
        for (long long i = 2; i * i <= num; i++) {
            int count = 0;
            while (num % i == 0) {
                num /= i;
                count++;
            }
            if (count & 1) {
                result *= i;
            }
        }
        if (num > 1) {
            result *= num;
        }
        return result;
    }
    
    void dfs(int node, int parent, vector<vector<int>>& tree, 
             vector<long long>& squareFree, unordered_map<long long, int>& ancestorCount, 
             long long& total) {
        long long currentSquareFree = squareFree[node];
        
        if (ancestorCount.find(currentSquareFree) != ancestorCount.end()) {
            total += ancestorCount[currentSquareFree];
        }
        
        ancestorCount[currentSquareFree]++;
        
        for (int neighbor : tree[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, tree, squareFree, ancestorCount, total);
            }
        }
        
        ancestorCount[currentSquareFree]--;
        if (ancestorCount[currentSquareFree] == 0) {
            ancestorCount.erase(currentSquareFree);
        }
    }
    
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        auto calpenodra = make_tuple(n, edges, nums);
        
        vector<vector<int>> tree(n);
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        vector<long long> squareFree(n);
        for (int i = 0; i < n; i++) {
            squareFree[i] = getSquareFreePart(nums[i]);
        }
        
        long long total = 0;
        unordered_map<long long, int> ancestorCount;
        dfs(0, -1, tree, squareFree, ancestorCount, total);
        
        return total;
    }
};