/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func helper(root *TreeNode, min_val int, max_val int) bool{
    if root == nil {
        return true
    }
    if root.Val <= min_val || root.Val >= max_val {
        return false
    }
    
    return helper(root.Left, min_val, root.Val) && helper(root.Right, root.Val, max_val)
                 
}
func isValidBST(root *TreeNode) bool {
    return helper(root,math.MinInt64, math.MaxInt64)
}
