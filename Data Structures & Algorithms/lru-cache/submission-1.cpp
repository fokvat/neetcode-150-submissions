class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Remove a node from the list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert a node right before tail (Most Recently Used)
    void insert(Node* node) {
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];

        // Move to MRU position
        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;

            remove(node);
            insert(node);
            return;
        }

        // Cache full -> remove LRU
        if (cache.size() == capacity) {
            Node* lru = head->next;

            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }

        // Insert new node
        Node* node = new Node(key, value);
        insert(node);
        cache[key] = node;
    }
};