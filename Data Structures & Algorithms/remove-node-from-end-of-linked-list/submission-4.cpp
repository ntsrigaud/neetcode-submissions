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
        ListNode dummy(0, head);
        auto* left = &dummy;
        auto* right = dummy.next;

        // Shift right after nth node from the end
        while (n > 0 && right != nullptr) {
            right = right->next;
            --n;
        }

        // Shift both pointers together until end
        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }

        // Skip the target nod
        auto* target = left->next;
        left->next = left->next->next;
        delete target;  // Prevent mem leaks

        return dummy.next;
    }
};
