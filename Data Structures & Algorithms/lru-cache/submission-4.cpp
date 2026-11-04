class LRUCache {
public:
    class ListNode {
        public: 
            int k;
            int val;
            ListNode* prev;
            ListNode* next;
            ListNode(int key, int value) {
                k = key;
                val = value;
                prev = NULL;
                next = NULL;
            } 
    };

    int cap;
    unordered_map<int, ListNode*> m;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) {
            return -1;
        }
        ListNode* node = m[key];
        if(node == head)
            return m[key]->val;
        ListNode* prevNode = node->prev;
        ListNode* nextNode = node->next;
        if(prevNode) {
            if(prevNode->next == tail) 
                tail = prevNode;
            prevNode->next = nextNode;
        }
        if(nextNode)
            nextNode->prev = prevNode;
        node->next = head;
        head->prev = node;
        head = node;

        return node->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            ListNode* node = m[key];
            node->val = value;
            get(key);
            return;
        }
        if(m.size() == cap) {
            ListNode* tailNode = tail;
            ListNode* prevNode = tail->prev;
            if(prevNode)
                prevNode->next = NULL;
            else
                head = NULL;
            tail = prevNode;
            m.erase(tailNode->k);
            delete tailNode;
        }
        ListNode* newNode = new ListNode(key, value);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        m[key] = newNode;
    }
};
