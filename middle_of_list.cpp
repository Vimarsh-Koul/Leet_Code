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
    ListNode* middleNode(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        
        ListNode* temp = head;
        ListNode* a = head;
        ListNode* b = head;
        
        // if(temp->next->next==NULL)
        //     return temp->next;
        if(temp->next==NULL)
            return head;
        
        while(b){
            a= a->next;
            b= b->next->next;
            
            if(b!=NULL){
                if(b->next==NULL)
                return a;
            }
            
        }
        
        return a;
        
    }
};