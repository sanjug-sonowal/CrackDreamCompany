// Last updated: 18/10/2025, 09:04:33
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

  void collectLeaves(TreeNode *root, vector<int> &leafValues) {
        if (!root) {
            return;
        }

        if (!root->left && !root->right) {
            leafValues.push_back(root->val);
        }

        collectLeaves(root->left, leafValues);
        collectLeaves(root->right, leafValues);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafSequence1, leafSequence2;
        collectLeaves(root1, leafSequence1);
        collectLeaves(root2, leafSequence2);
        return leafSequence1 == leafSequence2;
    }
};