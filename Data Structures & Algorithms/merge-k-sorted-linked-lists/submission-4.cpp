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
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        auto dummy = ListNode(0);
        auto* cur = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if (l1 || l2) {
            cur->next = l1 ? l1 : l2;
        }

        return dummy.next;
    }

   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        // Merge lists by pairs until only one is left
        while (lists.size() > 1) {
            std::vector<ListNode*> mergedLists;

            for (size_t i = 0; i < lists.size(); i += 2) {
                auto* l1 = lists[i];
                auto* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeLists(l1, l2));
            }

            lists = mergedLists;
        }

        return lists.front();
    }
};
