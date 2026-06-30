struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class MyHashSet {
private:
    vector<Node*> mpp;
    int size = 1009;
public:
    MyHashSet() {
        mpp.resize(size);
    }
    
    void add(int key) {
        int n = key % size;
        Node* temp = mpp[n];

        while(temp != nullptr) {
            if(temp -> val == key) return;
            if(temp -> next == nullptr) break;
            temp = temp -> next;
        }
        if(temp == nullptr) mpp[n] = new Node(key);
        else temp -> next = new Node(key);
    }
    
    void remove(int key) {
        int n = key % size;
        if(mpp[n] == nullptr) return;

        Node* temp = mpp[n]; 

        if(temp -> val == key) {
            mpp[n] = temp -> next;
            delete temp;
        } else {
            while(temp -> next != nullptr &&temp -> next -> val != key) temp = temp -> next;

            if(temp -> next != nullptr && temp -> next -> val == key) {
                Node* dele = temp -> next;
                temp -> next = dele -> next;
                delete dele;
            }
        }
    }
    
    bool contains(int key) {
        int n = key % size;
        Node* temp = mpp[n];

        while(temp != nullptr) {
            if(temp -> val == key) return true;
            temp = temp -> next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */