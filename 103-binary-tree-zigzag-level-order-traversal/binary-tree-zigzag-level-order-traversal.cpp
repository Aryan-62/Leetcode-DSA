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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Determine position based on current direction
                int index = leftToRight ? i : (levelSize - 1 - i);
                currentLevel[index] = node->val;

                // Push children to the queue in standard left-to-right order
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(move(currentLevel));
            leftToRight = !leftToRight; // Flip direction for the next level
        }

        return result;
    }
};