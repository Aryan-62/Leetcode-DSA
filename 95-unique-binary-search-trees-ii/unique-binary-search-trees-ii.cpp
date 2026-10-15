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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

private:
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> allTrees;

        // Base case: if start > end, there is no valid node, so return a list containing nullptr
        if (start > end) {
            allTrees.push_back(nullptr);
            return allTrees;
        }

        // Pick each number as the root
        for (int i = start; i <= end; ++i) {
            // Generate all valid left subtrees
            vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);

            // Generate all valid right subtrees
            vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);

            // Combine each left and right subtree with the current root `i`
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root);
                }
            }
        }

        return allTrees;
    }
};