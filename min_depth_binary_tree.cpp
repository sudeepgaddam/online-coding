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
    int min_level;
public:
    Solution(){
        min_level = 9999999;
    }
    void findMinDepth(TreeNode* root,int depth) {
        
        
        if (depth > min_level) {
            return;
        }
        if (root->left)
            findMinDepth(root->left, depth+1);
        if(root->right)
        findMinDepth(root->right, depth+1);
        if (!root->left && !root->right) {
            min_level =  min(min_level,depth); 
            return;

        }
    }
        
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        findMinDepth(root,1);
        return min_level;
        
    }
};
