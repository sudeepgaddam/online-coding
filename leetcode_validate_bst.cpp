/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBSTRec(TreeNode* root, long min, long max) {
        if(!root) return true;
        if((root->val<max) && (root->val>min)) {
            return (isValidBSTRec(root->left, min, root->val)) &&
                    (isValidBSTRec(root->right, root->val, max));
        }
        return false; 
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTRec(root, LONG_MIN, LONG_MAX);
    }
};
