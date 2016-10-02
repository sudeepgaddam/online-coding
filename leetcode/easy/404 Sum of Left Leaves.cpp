/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.


*/


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
    int sum;
public:

    void rec(TreeNode* root, bool left) {
        if(!root->left && !root->right && left) {
            sum+=root->val;
            
            return;
        }
        if(root->left)  rec(root->left, true);
        if(root->right)  rec(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum=0;
        if(root) rec(root,false);
        return sum;
        
    }
};
