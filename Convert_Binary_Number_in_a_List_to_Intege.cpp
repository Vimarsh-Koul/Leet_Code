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
    int getDecimalValue(ListNode* head) {
        if(head==NULL)
            return 0;
        ListNode *temp = head;
        int size=-1;
        while(temp){
            size++;
            temp=temp->next;
        }
        
        int ans =0;
        temp = head;
        while(temp){
            ans+= temp->val*(1<<size);
            size--;
            temp=temp->next;
        }
        return ans;
    }
};