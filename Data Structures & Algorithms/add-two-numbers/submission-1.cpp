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
        auto dummy = ListNode(0);
        auto* cur = &dummy;

        auto updateCarrySumRes = [&]() -> void {
            if (sum >= DEC_BASE) {
                carry = 1;
                sum -= DEC_BASE;
            } else {
                carry = 0;
            }

            cur->next = new ListNode(sum);
            cur = cur->next;
        };

        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            updateCarrySumRes();

            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* rest = l1 != nullptr ? l1 : l2;
        while (rest != nullptr) {
            sum = rest->val + carry;
            updateCarrySumRes();

            rest = rest->next;
        }

        if (carry) {
            cur->next = new ListNode(1);
        }

        return dummy.next;
    }
};
