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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp0,*temp1,*new_head, *new_tail;
        temp0 = l1;
        temp1 = l2;
        new_head = new_tail = NULL;
        
        if(l1==NULL || l2==NULL){
            if(l1==NULL)
                return l1;
            else
                return l2;
        }
        int carry =0;
        while(temp0!=NULL && temp1!=NULL){
            
            int data = temp0->val + temp1->val;
            if(carry>0){
                data= data+carry;
                carry = 0;
            }
            
            ListNode* temp = new ListNode();
            temp->val = data%10;
            carry = data/10;
            if(new_head==NULL){
                new_head= new_tail = temp;
                temp->next=NULL;
                
                }
            
            else{
                ListNode *last = new_tail;
                last->next = temp;
                temp->next=NULL;
                new_tail= temp;
            }
            
            temp0=temp0->next;
            temp1=temp1->next;
            
        }
        
        if(carry>0 && temp0==NULL && temp1==NULL){
             ListNode* temp = new ListNode();
            temp->val = carry;
             ListNode *last = new_tail;
                last->next = temp;
                temp->next=NULL;
                new_tail= temp;
            
        }
        
        else if(carry==0 && (temp0!=NULL || temp1!=NULL)){
            ListNode* temp3=NULL;
            if(temp0!=NULL){
                 temp3 = temp0;
                new_tail->next = temp3;
                return new_head;
                
            }
            else{
                temp3 = temp1;
                new_tail->next = temp3;
                return new_head;
            }
            
        }
        
        else{
        
        ListNode* temp3=NULL;
        if(temp0)
            temp3 = temp0;
        if(temp1)
            temp3 = temp1;
        
        while(temp3!=NULL && carry>0){
            
             int data = temp3->val;
            if(carry>0){
                data= data+carry;
                carry = 0;
            }
            ListNode* temp = new ListNode();
            temp->val = data%10;
            carry = data/10;
             ListNode *last = new_tail;
                last->next = temp;
                temp->next=NULL;
                new_tail= temp;
            
            temp3=temp3->next;
            
        }
            
            if(carry>0 && temp3==NULL){
             ListNode* temp = new ListNode();
            temp->val = carry;
             ListNode *last = new_tail;
                last->next = temp;
                temp->next=NULL;
                new_tail= temp;
            
        }
            
            if(temp3)
                new_tail->next = temp3;
            
        }
        
        return new_head;
    }
    
};