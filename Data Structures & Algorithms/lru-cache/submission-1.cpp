class LRUCache {
    static constexpr int NOT_FOUND = -1;
    class Node {
       public:
        int key;
        int val;
        Node* prev = nullptr;
        Node* next = nullptr;

        Node(int k, int v) : key(k), val(v) {};
    };

    int capacity = 0;
    std::unordered_map<int, Node*> cache;  // k -> node

    // Dummy ptrs for tracking least and most recent nodes
    Node* left = new Node(0, 0);
    Node* right = new Node(0, 0);

    // Helper functions
    void remove(Node* n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void insert(Node* node) {
        auto* prev_node = right->prev;

        prev_node->next = node;
        node->prev = prev_node;

        right->prev = node;
        node->next = right;
    }

   public:
    LRUCache(int cap) {
        capacity = cap;

        // Link dummy nodes
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return NOT_FOUND;

        auto* node = it->second;

        // Update the most recent
        remove(node);
        insert(node);

        return node->val;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            remove(it->second);
            delete it->second;
        }

        // Add new mapping
        cache[key] = new Node(key, value);
        insert(cache[key]);

        // Remove LRU if capacity exhausted
        if (cache.size() > capacity) {
            auto lru = left->next;
            remove(lru);

            cache.erase(lru->key);

            delete lru;
        }
    }
};
