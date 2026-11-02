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
        ListNode dummy = ListNode(0, head);

        // Track the previous group to link the next on to be reversed
        ListNode* prev_group = &dummy;

        auto getKthNode = [](ListNode* cur, int k) -> ListNode* {
            while (cur && k > 0) {
                --k;
                cur = cur->next;
            }

            return cur;
        };

        while (true) {
            // Retrieve kth node to get how big the group is
            auto* kth = getKthNode(prev_group, k);
            if (!kth) break;  // Last group

            // Track a node after the group for linking them
            auto* next_group = kth->next;

            // Reversing operation
            auto* prev = kth->next;  // Last node will become first
            auto* cur = prev_group->next;
            while (cur != next_group) {
                auto* tmp = cur->next;

                cur->next = prev;
                prev = cur;

                cur = tmp;
            }

            // Last node becomes first
            auto* tmp = prev_group->next;
            prev_group->next = kth;
            prev_group = tmp;
        }

        return dummy.next;
    }
};
