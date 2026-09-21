class Solution {
    ListNode* kthNode(ListNode* cur, int k) {
        while (cur && k > 0) {
            cur = cur->next;
            --k;
        }
        return cur;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        auto* group_prev = &dummy;

        while (true) {
            auto* kth = kthNode(group_prev, k);
            if (!kth) break; // Fewer than k nodes remaining

            auto* group_next = kth->next; // First node of the next group
            auto* prev = kth->next;
            auto* cur = group_prev->next;

            // Reverse the k nodes in the current group
            while (cur != group_next) {
                auto* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }

            // Re-link group_prev to the new head of this group (kth)
            auto* group_tail = group_prev->next;
            group_prev->next = kth;
            group_prev = group_tail; // Advance group_prev to tail for next round
        }

        return dummy.next;
    }
};