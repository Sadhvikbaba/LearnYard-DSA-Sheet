/* Node is defined as
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
    Node* segregate(Node* head) {
        int zeros = 0, ones = 0, twos = 0;
        
        for(Node* temp = head; temp != nullptr; temp = temp -> next) {
            if(temp -> data == 0) zeros++;
            else if(temp -> data == 1) ones++;
            else twos++;
        }
        
        Node* temp = head;
        
        for(int i = 0; i < zeros; i++, temp = temp -> next) temp -> data = 0;
        for(int i = 0; i < ones; i++, temp = temp -> next) temp -> data = 1;
        for(int i = 0; i < twos; i++, temp = temp -> next) temp -> data = 2;
        
        return head;
    }
};