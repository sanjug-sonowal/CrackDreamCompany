// Last updated: 18/10/2025, 09:04:25
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
    unordered_map<int, int> postorderMap;
    int preIndex = 0;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            postorderMap[postorder[i]] = i;
        }
        return construct(preorder, postorder, 0, n - 1);
    }

    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int postStart, int postEnd) {
        if (preIndex >= preorder.size() || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if (preIndex < preorder.size() && postStart <= postEnd) {
            int leftChild = preorder[preIndex];
            if (postorderMap[leftChild] <= postEnd) {
                root->left = construct(preorder, postorder, postStart, postorderMap[leftChild]);
                root->right = construct(preorder, postorder, postorderMap[leftChild] + 1, postEnd - 1);
            }
        }
        return root;
    }
};