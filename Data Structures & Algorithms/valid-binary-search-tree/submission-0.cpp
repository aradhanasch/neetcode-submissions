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
    bool check(TreeNode* root, int ub, int lb) {
        if(root == NULL)
            return true;
        if(root->val >= ub || root->val <= lb) 
            return false;
        
        bool l = check(root->left, root->val, lb);
        bool r = check(root->right, ub, root->val);
        return l && r;
    }
    bool isValidBST(TreeNode* root) {
        return check(root, INT_MAX, INT_MIN);
    }
};
