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
    ListNode* swapPairs(ListNode* head) {
        // Base case: 0 or 1 node doesn't need swapping
        if (!head || !head->next) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Ensure there is a pair left to swap
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Rewire pointers
            first->next = second->next; // 1 -> 3
            second->next = first;       // 2 -> 1
            prev->next = second;        // prev -> 2

            // Move prev to the end of the swapped pair
            prev = first;
        }

        return dummy.next;
    }
};