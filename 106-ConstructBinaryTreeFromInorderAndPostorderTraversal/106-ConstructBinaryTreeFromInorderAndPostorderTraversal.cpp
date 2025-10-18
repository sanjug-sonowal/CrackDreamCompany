// Last updated: 18/10/2025, 09:07:09
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> indexMap;
        for (int i = 0; i < n; i++) {
            indexMap[inorder[i]] = i;  // store value -> index
        }
        int postIndex = n - 1;
        return build(inorder, postorder, 0, n - 1, postIndex, indexMap);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd, int& postIndex,
                    unordered_map<int,int>& indexMap) {
        if (inStart > inEnd) return nullptr;

        // Last element in postorder = root
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find root index in inorder
        int inIndex = indexMap[rootVal];

        // Build right first (because of postorder)
        root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex, indexMap);
        root->left  = build(inorder, postorder, inStart, inIndex - 1, postIndex, indexMap);

        return root;
    }
};
