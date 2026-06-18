class Node{
public:
int key;
int value;
int cnt;
Node*prev;
Node*next;
   Node(int key,int value){
      this->key=key;
      this->value=value;
      cnt=1;
   }
};
class List{
public:    
    int size;
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    List(){
        head->next=tail;
        head->prev=nullptr;
        tail->prev=head;
        tail->next=nullptr;
        size=0;
    }
    void addFront(Node*node){
        Node*nextNode=head->next;
        node->next=nextNode;
        node->prev=head;
        head->next=node;
        nextNode->prev=node;
        size++;
    }
    void removeNode(Node*node){
        Node*nextNode=node->next;
        Node*prevNode=node->prev;
        nextNode->prev=prevNode;
        prevNode->next=nextNode;
        size--;
    }
};
class LFUCache {
public:
unordered_map<int,Node*>keyNode;
unordered_map<int,List*>freqList;
int maxCap;
int currCap;
int minFreq;
    LFUCache(int capacity) {
        maxCap=capacity;
        minFreq=0;
        currCap=0;
    }
    void updateFreqList(Node*node){
        freqList[node->cnt]->removeNode(node);
        if(node->cnt==minFreq && freqList[node->cnt]->size==0){
            minFreq++;
        }
        List *newList=new List();
        if(freqList.count(node->cnt+1)){
            newList=freqList[node->cnt+1];
        }
        node->cnt+=1;
        newList->addFront(node);
        freqList[node->cnt]=newList;
    }
    int get(int key) {
    if(!keyNode.count(key)) return -1;   
    Node*node=keyNode[key];
    updateFreqList(node);
    return node->value;
    }
    
    void put(int key, int value) {
        if(maxCap==0) return;
        if(keyNode.count(key)){
            Node*node=keyNode[key];
            node->value=value;
            updateFreqList(node);
        }else{
            if(currCap==maxCap){
                List *list=freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                currCap--;
            }
            currCap++;
            minFreq=1;
            List *newList=new List();
            if(freqList.count(minFreq)){
                newList=freqList[minFreq];
            }
            Node* newNode=new Node(key,value);
            newList->addFront(newNode);
            keyNode[key]=newNode;
            freqList[newNode->cnt]=newList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */