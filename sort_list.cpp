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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *mid = getmid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);
    }
    
    ListNode *merge(ListNode* left, ListNode* right){
        ListNode * head= new ListNode(0);
        ListNode *ptr = head;
        
        while(left && right){
            if(left->val<right->val){
                ptr->next = left;
                left=left->next;
            }
            
            else{
                ptr->next = right;
                right=right->next;
            }
            
            ptr=ptr->next;
        }
        
        if(left)
            ptr->next = left;
        else
            ptr->next = right;
        return head->next;
    }
    
    ListNode * getmid(ListNode *head){
        ListNode *midele = NULL;
        
        while(head && head->next){
            midele = (midele==NULL)?head: midele->next;
            head= head->next->next;
        }
        ListNode *mid = midele->next;
        midele->next = NULL;
        return mid;
    }
};