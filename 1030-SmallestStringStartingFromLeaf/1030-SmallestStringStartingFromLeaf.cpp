// Last updated: 18/10/2025, 09:04:00
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";

        string smallest = "|"; // Initialize with a character that is lexicographically larger than any lowercase letter
        dfs(root, "", smallest);
        
        return smallest;
    }
    
    void dfs(TreeNode* node, string path, string& smallest) {
        if (!node) return;

        path += char('a' + node->val); // Convert node value to corresponding character

        if (!node->left && !node->right) {
            reverse(path.begin(), path.end()); // Reverse the path to construct the string
            smallest = min(smallest, path); // Update the smallest string found so far
            return;
        }

        dfs(node->left, path, smallest); // Traverse left child
        dfs(node->right, path, smallest); // Traverse right child
    }
};