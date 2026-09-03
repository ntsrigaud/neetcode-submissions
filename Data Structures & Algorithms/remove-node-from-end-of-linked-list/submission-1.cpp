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
        int len = 1;
        auto* prev = head;
        auto* cur = prev->next;

        while (cur != nullptr) {
            prev = cur;
            cur = cur->next;
            ++len;
        }

        if (n == len) {
            return head->next;  // Drop the first item
        }

        prev = head;
        cur = prev->next;
        auto tmp_len = len;
        // Find node at nth position
        while (tmp_len > n + 1) {
            prev = cur;
            cur = cur->next;
            --tmp_len;
        }

        prev->next = (n == 1) ? nullptr : cur->next;

        return head;
    }
};
