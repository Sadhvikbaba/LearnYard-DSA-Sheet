/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
private:
    Node* merge(Node* list1, Node* list2){
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;

        while(list1 != nullptr && list2 != nullptr){
            if(list1 -> data < list2 -> data){
                temp -> bottom = list1;
                list1 = list1 -> bottom;
            }else{
                temp -> bottom = list2;
                list2 = list2 -> bottom;
            }
            temp = temp -> bottom;
        }

        if(list1 != nullptr)temp -> bottom = list1;
        else temp -> bottom = list2;

        return dummyNode -> bottom;
    }
public:
    Node *flatten(Node *root) {
        
        if(root == nullptr || root -> next == nullptr) return root;
        
        root -> next = flatten(root -> next);
        
        return merge(root, root -> next);
        
    }
};