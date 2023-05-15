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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        int a=arr[k-1];
        arr[k-1]=arr[n-k];
        arr[n-k]=a;

        ListNode* l1=new ListNode(arr[0]);
        temp=l1;
        for(int i=1;i<arr.size();i++){
            ListNode* l2=new ListNode(arr[i]);
            l1->next=l2;
            l1=l2;
        }
        return temp;
    }
};