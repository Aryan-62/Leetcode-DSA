/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        // Start with the root node.
        Node* leftmost = root;
        
        // Loop until we reach the last level. 
        // In a perfect binary tree, if there is no left child, we are at a leaf.
        while (leftmost->left != nullptr) {
            
            // Traverse the current level like a linked list
            Node* curr = leftmost;
            
            while (curr != nullptr) {
                // Connection 1: Connect the left child to the right child
                curr->left->next = curr->right;
                
                // Connection 2: Connect the right child to the next node's left child
                if (curr->next != nullptr) {
                    curr->right->next = curr->next->left;
                }
                
                // Move to the next node on the same level
                curr = curr->next;
            }
            
            // Move down to the next level
            leftmost = leftmost->left;
        }
        
        return root;
    }
};