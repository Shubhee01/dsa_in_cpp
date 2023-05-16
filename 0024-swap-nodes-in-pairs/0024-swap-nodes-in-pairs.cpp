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
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* cur=head;
        ListNode* fut=head;
        while(fut->next!=NULL){
            fut=cur->next;
            if(fut==NULL || cur==NULL){
                return head;
            }
            swap(cur->val,fut->val);
            cur=fut->next;
        }
        return head;
    }
};