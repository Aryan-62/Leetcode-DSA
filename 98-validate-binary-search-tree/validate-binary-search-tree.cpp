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
private:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        // An empty node is valid
        if (!node) return true;
        
        // Current node's value must be strictly within the allowed range
        if (node->val <= minVal || node->val >= maxVal) return false;
        
        // Recursively check left and right subtrees with updated bounds
        return validate(node->left, minVal, node->val) && 
               validate(node->right, node->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        // Start with the full range of possible values using long long
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};