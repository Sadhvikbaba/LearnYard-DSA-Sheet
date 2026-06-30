/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* node;
public:
    Solution(ListNode* head) {
        node = head;
    }
    
    int getRandom() {
        int ans = node -> val, i = 1;
        for(ListNode* temp = node; temp != nullptr; i++, temp = temp -> next) {
            if(rand() % i == 0) ans = temp -> val;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */