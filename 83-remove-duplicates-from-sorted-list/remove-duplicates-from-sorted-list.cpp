/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // If the list is empty, return nullptr
        if (head == nullptr) return nullptr;
        
        ListNode* current = head;
        
        // Traverse through the list
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Duplicate found: skip the next node
                current->next = current->next->next;
            } else {
                // No duplicate: move to the next node
                current = current->next;
            }
        }
        
        return head;
    }
};