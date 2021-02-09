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
    bool isPalindrome(ListNode* head) {
        ListNode* slow,*fast;
        
        slow=fast=head;
        if(head ==NULL or slow->next==NULL)
            return true;
        
        while(fast && fast->next!=NULL){
            
            fast = fast->next->next;
            slow = slow->next;
            }
        
        
        ListNode *new_tail = NULL;
        ListNode* slow_copy = slow;
        while(slow){
            
            ListNode * temp = slow->next;
            slow->next = new_tail;
            new_tail = slow;
            slow = temp;
        }
        ListNode *head0,*head1;
        head0 = head;
        head1 = new_tail;
        
        while(head1){
            if(head1->val!=head0->val)
                return false;
            head0=head0->next;
            head1=head1->next;
        }
        return true;
    }
};