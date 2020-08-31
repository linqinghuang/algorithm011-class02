struct CacheNode {
    int key;
    int value;
    CacheNode* pre;
    CacheNode* nex;
    CacheNode(int key_ = 0, int value_ = 0) : key(key_), value(value_), pre(nullptr), nex(nullptr) {}; 
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), head(new CacheNode()), tail(head){}
    ~LRUCache() {
        while(head != nullptr) {
            auto next = head->nex;
            delete head;
            head = next;
        }
    }
    int get(int key) {
        auto it = _cache.find(key);
        if (it == _cache.end()) return -1;
        moveToTail(it->second);

        return it->second->value;
    }
    
    void put(int key, int value) {
        auto it = _cache.find(key);
        if (it != _cache.end()) {
            it->second->value = value;
            moveToTail(it->second);
        }
        else if (_cache.size() < capacity) {
            auto tmp = new CacheNode(key, value);
            _cache[key] = tmp;
            addToTail(tmp);
        }
        else {
            //delete head
            _cache.erase(head->nex->key);
            moveToTail(head->nex);
            tail->key = key;
            tail->value = value;
            _cache[key] = tail;
        }
    }
private:
    void moveToTail(CacheNode* node) {
        if (node == tail) return;
        node->pre->nex = node->nex;
        node->nex->pre = node->pre;        
        addToTail(node);
    }

    void addToTail(CacheNode* node) {
        node->nex = tail->nex;
        tail->nex = node;
        node->pre = tail;
        tail = node;
    }

    int capacity = 0;
    CacheNode* head = nullptr;
    CacheNode* tail = nullptr;
    unordered_map<int, CacheNode*> _cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */