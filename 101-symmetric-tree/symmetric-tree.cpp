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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // If both nodes are null, they are symmetric
        if (!t1 && !t2) return true;
        
        // If only one is null, or values don't match, they aren't symmetric
        if (!t1 || !t2 || t1->val != t2->val) return false;
        
        // Check outer pairs (t1->left and t2->right) and inner pairs (t1->right and t2->left)
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};