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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode dummy(0, head);
        ListNode* left = &dummy;

        // Move right by n steps
        ListNode* right = head;
        while (n-- > 0 && right) right = right->next;

        // Shift both ptrs together until right reaches end
        while (right) {
            left = left->next;
            right = right->next;
        }

        // Unlink and free target node
        ListNode* to_delete = left->next;
        if (to_delete) {
            left->next = to_delete->next;
            delete to_delete;
        }

        return dummy.next;
    }
};
