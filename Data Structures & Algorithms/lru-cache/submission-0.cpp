class Node {
   public:
    // Double linked list node
    int val;
    int key;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int k, int v) : key(k), val(v) {};
};

class LRUCache {
    static constexpr int INVALID = -1;

    int cap = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    std::unordered_map<int, Node*> cache;

    // Helper methods to manage DLL
    void remove(Node* node) {
        // Evict LRU from left
        auto* prev = node->prev;
        auto* next = node->next;

        prev->next = node->next;
        next->prev = node->prev;
    }

    void insert(Node* node) {
        // Insert to the right as MRU
        auto* prev = right->prev;

        // Link right links
        right->prev = node;
        node->next = right;

        // Link left links
        prev->next = node;
        node->prev = prev;
    }

   public:
    LRUCache(int capacity) : cap(capacity) {
        // Init dummy LR ptrs for LRU node retrieval
        left = new Node(0, 0);
        right = new Node(0, 0);

        // Link them to form the list
        left->next = right;
        right->prev = left;
    }

    ~LRUCache() {
        Node* curr = left;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return INVALID;

        Node* node = it->second;

        remove(node);
        insert(node);  // Move to MRU

        return node->val;
    }

    void put(int key, int value) {
        // Retrieve any node associated with input key
        auto it = cache.find(key);

        if (it != cache.end()) {
            // Update value in-place without re-allocating
            Node* node = it->second;
            node->val = value;
            remove(node);
            insert(node);
            return;
        }

        // Evict LRU node if full
        if (static_cast<int>(cache.size()) == cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }

        // Insert new node as MRU
        auto* new_node = new Node(key, value);
        insert(new_node);
        cache[key] = new_node;
    }
};
