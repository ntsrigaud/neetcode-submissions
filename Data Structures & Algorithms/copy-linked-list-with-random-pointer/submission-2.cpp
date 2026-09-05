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
        // Hash the nodes to initialize the random ptrs
        std::unordered_map<Node*, Node*> ref_map;

        // Copy and allocate memory for each nodes
        Node* cur = head;
        while (cur != nullptr) {
            ref_map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // Link list and init random ptrs
        cur = head;
        while (cur != nullptr) {
            auto* copy = ref_map[cur];  // Avoids hash map heap overhead
            copy->next = ref_map[cur->next];
            copy->random = ref_map[cur->random];
            cur = cur->next;
        }

        return ref_map[head];
    }
};
