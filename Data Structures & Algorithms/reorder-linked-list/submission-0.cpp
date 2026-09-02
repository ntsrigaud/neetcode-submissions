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
        // Find middle node
        auto* slow = head;
        auto* fast = head->next;

        auto reverseList = [](ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* tmp = nullptr;

            while (head != nullptr) {
                tmp = head->next;   // Save before breaking link
                head->next = prev;  // Breaks the link at the start
                prev = head;
                head = tmp;  // Shift for next iteration
            }

            return prev;
        };

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Break the list in half at the middle node
        auto* first_half = head;
        auto* scond_half = slow->next;
        slow->next = nullptr;

        // Reverse the list
        scond_half = reverseList(scond_half);

        // Merge the two list -> Second part might be shorter
        while (scond_half != nullptr) {
            // Save next links before breaking them
            auto* tmp1 = first_half->next;
            auto* tmp2 = scond_half->next;

            first_half->next = scond_half;
            scond_half->next = tmp1;

            // Shift the pointers for next elts
            first_half = tmp1;
            scond_half = tmp2;
        }
    }
};
