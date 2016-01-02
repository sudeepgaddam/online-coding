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
    bool isBalanced(TreeNode* root) {
    return height(root).first;
    }
    
    
    pair<bool,int>  height(TreeNode* root) {
        if(!root) return make_pair(true,0);
        auto left = height(root->left);
        auto right = height(root->right);
        if(!left.first || !right.first) return make_pair(false,0);
        auto left_height = left.second;
        auto right_height = right.second;
        bool balanced = ((abs(left_height-right_height)) <= 1);
        int height = 1+ max(left_height,right_height);
        return make_pair(balanced,height);
    }
};
