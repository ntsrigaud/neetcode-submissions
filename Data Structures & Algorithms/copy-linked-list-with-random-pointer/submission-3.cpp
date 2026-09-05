/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // Copy and allocate memory for each nodes while interleaving them with the originals
        Node* cur = head;
        while (cur != nullptr) {
            // Cache original pointers in CPU register
            auto* next_orig = cur->next;
            auto* copy = new Node(cur->val);

            cur->next = copy;        // A -> A'
            copy->next = next_orig;  // A -> A' -> B
            cur = next_orig;
        }

        // Initialize the random ptrs from the interleaved list
        cur = head;
        while (cur != nullptr) {
            // Link current node next node's rd node to random next node
            if (cur->random != nullptr) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        // Separate the interleaved lists
        auto* head_copy = head->next;
        cur = head;
        while (cur != nullptr) {
            // Construct cloned list in parallel
            auto* copy = cur->next;
            cur->next = copy->next;

            if (copy->next != nullptr) {
                copy->next = copy->next->next;
            }

            cur = cur->next;
        }

        return head_copy;
    }
};
