class Node {
public:
	int key, val, freq;
	Node* next;
	Node* prev;
    
	Node() {
		key = val = -1;
        freq = 0;
		next = prev = NULL;
	}

	Node(int k, int value) {
		key = k;
		val = value;
        freq = 1;
		next = prev = NULL;
	}
};

class List {
public:
    Node* head;
    Node* tail;
    int size;

    List() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void remove(Node* node){
        Node* prevNode = node -> prev;
        Node* nextNode = node -> next;

        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
        size--;
    }

    void addFront(Node* node){
        Node* nextNode = head -> next;
        head -> next = node;
        nextNode -> prev = node;
        node -> prev = head;
        node -> next = nextNode;
        size++;
    }
};

class LFUCache {
private:
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;
    int minFreq, cap;

    void updateFreq(Node* node){
        List* oldList = freqList[node -> freq];
        oldList -> remove(node);

        if(node->freq == minFreq && oldList -> size == 0) minFreq++;
        node -> freq++;

        auto it = freqList.find(node->freq);

        if(it == freqList.end()) {
            freqList[node->freq] = new List();
        }

        freqList[node->freq]->addFront(node);
    }

public:
    LFUCache(int capacity) {
        minFreq = 0;
        cap = capacity;
    }
    
    int get(int key) {
        auto it = keyNode.find(key);

        if(it == keyNode.end()) return -1;

        updateFreq(it -> second);

        return it ->second -> val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        auto it = keyNode.find(key);

        if(it != keyNode.end()) {
            it ->second -> val = value;
            updateFreq(it -> second);
        } else {
            if(cap == keyNode.size()) {
                List* list = freqList[minFreq];
                Node* temp = list -> tail -> prev;

                list -> remove(temp);
                keyNode.erase(temp -> key);
                delete temp;
            }

            Node* node = new Node(key,value);
            keyNode[key]=node;

            if(freqList.find(1) == freqList.end()) freqList[1] = new List();

            freqList[1] -> addFront(node);
            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */