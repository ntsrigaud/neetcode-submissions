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
    static constexpr int DEC_BASE = 10;

   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        int a = 0;
        int b = 0;
        auto dummy = ListNode(0);
        auto* cur = &dummy;

        while (l1 != nullptr || l2 != nullptr) {
            a = l1 != nullptr ? l1->val : 0;
            b = l2 != nullptr ? l2->val : 0;

            sum = a + b + carry;
            carry = sum / DEC_BASE;
            cur->next = new ListNode(sum % DEC_BASE);

            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
            cur = cur->next;
        }

        if (carry) {
            cur->next = new ListNode(carry);
        }

        return dummy.next;
    }
};
