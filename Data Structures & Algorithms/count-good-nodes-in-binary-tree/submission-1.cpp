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
    int count(TreeNode* root, int mx) {
        if(root == NULL)
            return 0;
        int res = (root->val >= mx) ?  1 : 0;
        mx = max(mx, root->val);
        int l = count(root->left, mx);
        int r = count(root->right, mx);
        return res + l + r;
    }
    int goodNodes(TreeNode* root) {
        int mx = -101;
        return count(root, mx);
    }
};
