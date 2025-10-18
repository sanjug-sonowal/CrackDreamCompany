// Last updated: 18/10/2025, 09:06:34
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return 0;
        //swapping
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;

        //call recursively both left then right
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};