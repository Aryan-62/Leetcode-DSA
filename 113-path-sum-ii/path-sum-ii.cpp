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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        dfs(root, targetSum, currentPath, result);
        return result;
    }
    
private:
    void dfs(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!node) return;
        
        // Add current node to the path
        currentPath.push_back(node->val);
        
        // Check if it's a leaf node and the remaining sum equals the node's value
        if (!node->left && !node->right && targetSum == node->val) {
            result.push_back(currentPath);
        } else {
            // Recurse for left and right children
            dfs(node->left, targetSum - node->val, currentPath, result);
            dfs(node->right, targetSum - node->val, currentPath, result);
        }
        
        // Backtrack to explore other paths
        currentPath.pop_back();
    }
};