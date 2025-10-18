// Last updated: 18/10/2025, 09:07:12
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p || !q)
      return p == q;
    return p->val == q->val &&              //
           isSameTree(p->left, q->left) &&  //
           isSameTree(p->right, q->right);
  }
};