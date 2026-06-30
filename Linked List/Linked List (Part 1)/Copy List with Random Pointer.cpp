/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        unordered_map<Node*, Node*> map;
        Node* ans = dummy;
        Node* index = head;

        // First pass: Create copy of nodes and build next links.
        while (index) {
            Node* newNode = new Node(index->val); // New node
            ans->next = newNode; // Link new node to the copied list.
            ans = newNode;      // Move ans to the newly created node.
            map[index] = newNode; // Map original node to its copy.
            index = index->next; // Map original node to its copy.
        }

        index = dummy->next; // Reset index to start of copied list.

        // Second pass: Set random pointers using the map.
        while (head) {
            if (head->random) {
                // Set random pointer of copied node.
                index->random = map[head->random]; 
            } 
            else {
                // If original random is NULL, set it as NULL.
                index->random = NULL;
            }
            head = head->next;
            index = index->next;
        }

        ans = dummy->next;
        delete dummy;
        return ans;
    }
};