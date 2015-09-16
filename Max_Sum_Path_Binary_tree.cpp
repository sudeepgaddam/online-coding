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
    
    private:
    int max_global;
    public:
    int maxPathSum(TreeNode* root) {
        max_global = root->val;
        maxSum(root);
        return max_global;
    }
    int maxSum(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) {
            max_global = std::max(max_global,root->val);
            return root->val;
        }
        int left_val = maxSum(root->left);
        int right_val = maxSum(root->right); 
        int max_local = std::max(root->val, std::max(left_val+root->val, right_val+root->val));
        max_global = std::max(max_local, std::max(left_val+right_val+root->val, max_global));
        return max_local;
    }
};
