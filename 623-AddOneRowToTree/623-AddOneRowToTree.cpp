// Last updated: 18/10/2025, 09:05:17
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // If depth is 1, create a new root and assign the original tree as its left child
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        // Perform BFS to reach the desired depth
        std::queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;
        
        while (!q.empty()) {
            int size = q.size();
            // Process nodes at the current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                // If currentDepth is depth - 1, insert new nodes
                if (currentDepth == depth - 1) {
                    TreeNode* leftNode = new TreeNode(val);
                    TreeNode* rightNode = new TreeNode(val);
                    // Adjust pointers according to the rules
                    leftNode->left = node->left;
                    rightNode->right = node->right;
                    node->left = leftNode;
                    node->right = rightNode;
                } else {
                    // Add child nodes to the queue if they exist
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            // Increment currentDepth after processing each level
            if (++currentDepth == depth) break;
        }
        
        return root;
    }
};
