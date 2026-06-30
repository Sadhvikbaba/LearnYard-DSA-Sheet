/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* addOne(Node* head) {
        Node* temp = new Node(0);
        temp -> next = head;
        Node *lastNonNine = temp, *curr = head;
        
        while(curr != nullptr) {
            if(curr -> data != 9) lastNonNine = curr;
            curr = curr -> next;
        }
        
        lastNonNine -> data++;
        curr = lastNonNine -> next;
        
        while(curr != nullptr) {
            curr -> data = 0;
            curr = curr -> next;
        }
        return temp -> data ? temp : temp -> next;
    }
};