/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  private:
    int func(Node* head) {
        Node* temp = head;
        int cnt = 1;
        temp = temp -> next;
        
        while(temp != head) {
            temp = temp -> next;
            cnt++;
        }
        return cnt;
    }
  public:
    int lengthOfLoop(Node *head) {
        Node *slow = head, *fast = head;
        
        while(fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if(slow == fast) return func(slow);
        }
        return 0;
    }
};