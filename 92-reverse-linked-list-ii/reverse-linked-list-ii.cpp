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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node handles the edge case where left == 1
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        // 1. Move 'prev' to the node right before position 'left'
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // 'curr' is the first node of the sublist to be reversed.
        // It will gradually sink to the end of the reversed sublist.
        ListNode* curr = prev->next;

        // 2. Repeatedly take 'curr->next' and move it right after 'prev'
        for (int i = 0; i < right - left; ++i) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }
};