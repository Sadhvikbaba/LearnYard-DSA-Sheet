struct Node {
    int val;
    unordered_set<string> keys;
    Node *prev, *next;

    Node() : val(0) , next(nullptr), prev(nullptr) {}
    Node(int val) : val(val) , next(nullptr), prev(nullptr) {}
    Node(int val, Node* prev, Node* next) : val(val), prev(prev), next(next) {}
};

class AllOne {
private:
    unordered_map<string, Node*> mpp;
    Node *head, *tail;

    Node* insert(Node* curr, int count) {
        Node* temp = new Node(count);

        temp -> next = curr -> next;
        temp -> prev = curr;

        curr -> next -> prev = temp;
        curr -> next = temp;

        return temp;
    }

    void remove(Node* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        delete node;
    }

public:
    AllOne() {
        head = new Node();
        tail = new Node();

        head -> next = tail;
        tail -> prev = head;
    }
    
    void inc(string key) {
        auto it = mpp.find(key);
        Node* temp = nullptr;

        if(it == mpp.end()) {
            if(head -> next == tail || head -> next -> val != 1) {
                temp = insert(head, 1);
            } else {
                temp = head -> next;
            }

            temp -> keys.insert(key);
            mpp[key] = temp;
        } else {
            Node* curr = it -> second;

            temp = curr -> next;

            if(temp == tail || temp -> val != curr -> val + 1) {
                temp = insert(curr, curr -> val + 1);

            }

            temp -> keys.insert(key);
            mpp[key] = temp;

            curr -> keys.erase(key);
            if(curr -> keys.empty()) remove(curr);
        }
    }
    
    void dec(string key) {
        auto it = mpp.find(key);
        Node* curr = it -> second;
        Node* temp;

        if(curr -> val == 1) {
            curr -> keys.erase(key);
            if(curr -> keys.empty()) remove(curr);
            mpp.erase(key);
            return ;
        } else if(curr -> prev -> val == curr -> val - 1) {
            temp = curr -> prev;
        } else temp = insert(curr -> prev, curr -> val - 1);
        temp -> keys.insert(key);
        curr -> keys.erase(key);
        mpp[key] = temp;
        if(curr -> keys.empty()) remove(curr);
    }
    
    string getMaxKey() {
        if(head -> next == tail) return "";
        return *tail -> prev -> keys.begin();
    }
    
    string getMinKey() {
        if(head -> next == tail) return "";
        return *head -> next -> keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */