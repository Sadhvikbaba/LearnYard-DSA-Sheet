struct Node {
    int val, key;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x, int y) : key(x), val(y), next(nullptr) {}
    Node(int x, int y, Node *next) : key(x), val(y), next(next) {}
};

class MyHashMap {
private:
    vector<Node*> mpp;
    int size = 1009;

public:
    MyHashMap() {
        mpp.resize(size);
    }
    
    void put(int key, int value) {
        int n = key % size;
        Node* temp = mpp[n];

        while(temp != nullptr) {
            if(temp -> key == key) {
                temp -> val = value;
                return;
            };
            if(temp -> next == nullptr) break;
            temp = temp -> next;
        }
        if(temp == nullptr) mpp[n] = new Node(key, value);
        else temp -> next = new Node(key, value);
    }
    
    int get(int key) {
        int n = key % size;
        Node* temp = mpp[n];

        while(temp != nullptr) {
            if(temp -> key == key) return temp -> val;
            temp = temp -> next;
        }
        return -1;
    }
    
    void remove(int key) {
        int n = key % size;
        if(mpp[n] == nullptr) return;

        Node* temp = mpp[n]; 

        if(temp -> key == key) {
            mpp[n] = temp -> next;
            delete temp;
        } else {
            while(temp -> next != nullptr &&temp -> next -> key != key) temp = temp -> next;

            if(temp -> next != nullptr && temp -> next -> key == key) {
                Node* dele = temp -> next;
                temp -> next = dele -> next;
                delete dele;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */