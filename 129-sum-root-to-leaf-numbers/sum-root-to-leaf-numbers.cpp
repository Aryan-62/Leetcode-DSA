/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) {
            return 0;
        }
        
        // Append current digit to the path number
        currentSum = currentSum * 10 + node->val;
        
        // If we hit a leaf node, return the formed number
        if (!node->left && !node->right) {
            return currentSum;
        }
        
        // Otherwise, sum the results from left and right subtrees
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }

public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};