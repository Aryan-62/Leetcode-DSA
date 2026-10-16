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
    ListNode* partition(ListNode* head, int x) {
        // Dummy heads for the two separate partitions
        ListNode beforeDummy(0);
        ListNode afterDummy(0);
        
        ListNode* before = &beforeDummy;
        ListNode* after = &afterDummy;
        
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                before->next = curr;
                before = before->next;
            } else {
                after->next = curr;
                after = after->next;
            }
            curr = curr->next;
        }
        
        // Crucial step: prevent a cycle in the list
        after->next = nullptr;
        
        // Connect the 'before' list with the 'after' list
        before->next = afterDummy.next;
        
        return beforeDummy.next;
    }
};