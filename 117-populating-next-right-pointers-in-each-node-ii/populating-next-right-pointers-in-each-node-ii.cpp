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
        Node* curr = root;
        
        while (curr != nullptr) {
            Node dummy(0);      // Dummy node for the start of the next level
            Node* prev = &dummy; // Prev pointer to build the next level's list
            
            // Traverse the current level
            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    prev->next = curr->left;
                    prev = prev->next;
                }
                if (curr->right != nullptr) {
                    prev->next = curr->right;
                    prev = prev->next;
                }
                // Move to the next node in the current level
                curr = curr->next;
            }
            
            // Move down to the next level
            curr = dummy.next;
        }
        
        return root;
    }
};