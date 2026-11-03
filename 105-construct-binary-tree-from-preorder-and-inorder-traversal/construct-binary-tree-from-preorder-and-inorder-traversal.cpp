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
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the indices of inorder elements for O(1) lookup
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        return build(preorder, 0, preorder.size() - 1, 
                     inorder, 0, inorder.size() - 1, inMap);
    }

private:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                    vector<int>& inorder, int inStart, int inEnd, 
                    unordered_map<int, int>& inMap) {
        
        // Base case: if boundaries cross, there's no node to construct
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        
        // The first element in the current preorder range is the root
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        // Find where this root is in the inorder traversal
        int inRoot = inMap[root->val];
        
        // Calculate the number of nodes in the left subtree
        int numsLeft = inRoot - inStart;
        
        // Recursively build the left and right subtrees
        root->left = build(preorder, preStart + 1, preStart + numsLeft, 
                           inorder, inStart, inRoot - 1, inMap);
                           
        root->right = build(preorder, preStart + numsLeft + 1, preEnd, 
                            inorder, inRoot + 1, inEnd, inMap);
                            
        return root;
    }
};