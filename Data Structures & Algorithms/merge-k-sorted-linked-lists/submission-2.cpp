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
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        auto* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }

   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int interval = 1;
        const auto n = static_cast<int>(lists.size());

        while (interval < n) {
            // In-place pairwise merge
            // Safely access elts -> i + n < interval
            for (int i = 0; i < n - interval; i += interval * 2) {
                lists[i] = mergeList(lists[i], lists[i + interval]);
            }

            // Each round halves the remaining number of active sublists
            // We need to match the stride length between surviving sublists
            interval *= 2;
        }

        return lists.front();
    }
};
