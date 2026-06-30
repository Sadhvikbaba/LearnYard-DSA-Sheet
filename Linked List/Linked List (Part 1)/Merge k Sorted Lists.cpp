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
private:
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(list1 != nullptr && list2 != nullptr){
            if(list1 -> val < list2 -> val){
                temp -> next = list1;
                list1 = list1 -> next;
            }else{
                temp -> next = list2;
                list2 = list2 -> next;
            }
            temp = temp -> next;
        }

        if(list1 != nullptr)temp -> next = list1;
        else temp -> next = list2;

        return dummyNode -> next;
    }

    ListNode* solve(vector<ListNode*>& lists, int l, int r) {
        if(l == r) return lists[l];

        int mid = l + (r - l) / 2;

        ListNode* left = solve(lists, l, mid);
        ListNode* right = solve(lists, mid + 1, r);

        return merge(left, right);
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        return solve(lists, 0, lists.size() - 1);
    }
};