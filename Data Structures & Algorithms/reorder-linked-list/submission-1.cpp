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
    void reorderList(ListNode* head) {
        if (!head) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Break the list in the middle
        ListNode* second_half = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        // Reverse second portion of the list
        while (second_half) {
            auto* tmp = second_half->next;
            second_half->next = prev;
            prev = second_half;
            second_half = tmp;
        }

        // Merge two halves
        auto* first_half = head;
        second_half = prev;
        while (second_half) {
            auto* tmp1 = first_half->next;
            auto* tmp2 = second_half->next;

            // Alternately taking one from first_half and from second_half
            first_half->next = second_half;
            second_half->next = tmp1;

            // Shift Pointers
            first_half = tmp1;
            second_half = tmp2;
        }
    }
};
