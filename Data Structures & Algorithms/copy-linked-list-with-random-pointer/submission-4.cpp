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
        std::unordered_map<Node*, Node*> copy_map;
        copy_map[nullptr] = nullptr;  // Edge case for non-existing pointers in 2nd pass

        // First pass -> Deep copy of all the nodes w/o random
        auto* cur = head;
        while (cur) {
            auto* copy = new Node(cur->val);
            copy_map[cur] = copy;  // Map old to copy
            cur = cur->next;
        }

        // Second pass -> Set the pointers
        cur = head;
        while (cur) {
            auto* copy = copy_map[cur];
            copy->next = copy_map[cur->next];
            copy->random = copy_map[cur->random];

            cur = cur->next;
        }

        return copy_map[head];
    }
};
