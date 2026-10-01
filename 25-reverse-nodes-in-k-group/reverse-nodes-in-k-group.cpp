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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;

        while (true) {
            // 1. Check if there are at least k nodes remaining
            ListNode* kthNode = prevGroupTail;
            for (int i = 0; i < k && kthNode != nullptr; ++i) {
                kthNode = kthNode->next;
            }
            if (!kthNode) break; // Fewer than k nodes remain

            ListNode* nextGroupHead = kthNode->next;
            
            // 2. Reverse the current k-group
            ListNode* curr = prevGroupTail->next;
            ListNode* prev = nextGroupHead; // Pointing to nextGroupHead connects reversed tail automatically
            ListNode* groupHead = curr;     // This will become the tail after reversal

            for (int i = 0; i < k; ++i) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // 3. Connect the previous group's tail to the new head of this reversed group
            prevGroupTail->next = kthNode;
            
            // 4. Move prevGroupTail forward to the end of the newly reversed group
            prevGroupTail = groupHead;
        }

        return dummy.next;
    }
};