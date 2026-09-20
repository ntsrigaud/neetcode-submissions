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

        while (lists.size() > 1) {
            std::vector<ListNode*> mergedLists;

            // Iteratively merge pairs of sub-lists
            const auto n = static_cast<int>(lists.size());
            for (int i = 0; i < n; i += 2) {
                if (i + 1 == n) {
                    // Odd size list
                    mergedLists.push_back(lists[i]);
                } else {
                    mergedLists.push_back(mergeList(lists[i], lists[i + 1]));
                }
            }

            // Promote merged list
            lists = std::move(mergedLists);
        }

        return lists.front();
    }
};
