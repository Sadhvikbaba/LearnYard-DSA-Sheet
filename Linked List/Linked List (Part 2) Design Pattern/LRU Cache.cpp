class Node {
public:
	int key, val;
	Node* next;
	Node* prev;
    
    // Constructors
	Node() {
		key = val = -1;
		next = prev = NULL;
	}

	Node(int k, int value) {
		key = k;
		val = value;
		next = prev = NULL;
	}
};

class LRUCache {
private:
  unordered_map<int, Node*> mpp;
  int cap;
  Node* head;
  Node* tail;

  void deleteNode(Node* node){
    Node* prevNode = node -> prev;
    Node* nextNode = node -> next;

    prevNode -> next = nextNode;
    nextNode -> prev = prevNode;
  }

  void insertAfterHead(Node* node){
    Node* nextNode = head -> next;
    head -> next = node;
    nextNode -> prev = node;
    node -> prev = head;
    node -> next = nextNode;
  }

public:
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();

        head = new Node();
        tail = new Node();

        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end())return -1;

        Node* node = mpp[key];
        int val = node -> val;

        deleteNode(node);
        insertAfterHead(node);

        return val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node -> val = value;
            
            deleteNode(node);
            insertAfterHead(node);

            return;
        }
        if(mpp.size() == cap){
            Node* node = tail -> prev;
            mpp.erase(node -> key);
            deleteNode(node);
        }

        Node* node = new Node(key, value);
        mpp[key] = node;

        insertAfterHead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */