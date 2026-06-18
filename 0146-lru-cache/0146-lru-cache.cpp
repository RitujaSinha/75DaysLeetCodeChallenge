class LRUCache {
public:
    class Node{
    public: 
    
        int key, val;
        Node* prev;
        Node* next;

        Node(int key_, int val_){
            key = key_;
            val = val_;
            prev= NULL;
            next = NULL;
        }
    };

    unordered_map<int, Node* > mpp;
    int capacity;
    Node* head;
    Node* tail; 

    LRUCache(int capacity_){
        capacity = capacity_;
        
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* afterNode = node->next;

        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }

     void insertAfterHead(Node* node){
        Node* currAfterHead = head->next;

        head->next = node;
        node->prev = head;

        node->next = currAfterHead;
        currAfterHead->prev = node;
    }
    
    int get(int key) {
        
        if(mpp.find(key) == mpp.end()) return -1;

        Node* node = mpp[key];

        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];

            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        } else{
            if(mpp.size() == capacity){
                Node * node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }

            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */