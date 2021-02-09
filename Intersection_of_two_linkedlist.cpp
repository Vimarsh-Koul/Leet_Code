/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *h0 = headA;
        ListNode *h1 = headB;
        
        if(h0==NULL || h1==NULL)
            return NULL;
        
        int counter0,counter1;
        counter0 = counter1 =1;
        
        while(h0->next!=NULL){
            counter0++;
            h0 =h0->next;
            }
        while(h1->next!=NULL){
            
            counter1++;
            h1=h1->next;
            }
        
        if(h0!=h1)
            return NULL;
        
        ListNode* large, *small;
        large = small = NULL;
        if(counter0> counter1){
            large = headA;
            small = headB;
        }
        else{
            large = headB;
            small = headA;
            }
        int diff = abs(counter0-counter1);
        while(diff--){
            // cout<<large->val<<" ";
                large=large->next;
            // cout<<large->val;
            }
        
        // cout<<large->val;
        while(large!=small){
            large=large->next;
            small=small->next;
        }
        
        return large;
           
    }
};