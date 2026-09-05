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
            auto* new_node = new Node(cur->val);
            new_node->next = cur->next;  // A' -> B
            cur->next = new_node;        // A -> A' -> B
            cur = cur->next->next;
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
        auto dummy = Node(0);
        auto* cur_copy = &dummy;

        cur = head;
        while (cur != nullptr) {
            cur_copy->next = cur->next;
            cur->next = cur->next->next;

            cur = cur->next;
            cur_copy = cur_copy->next;
        }

        return dummy.next;
    }
};
