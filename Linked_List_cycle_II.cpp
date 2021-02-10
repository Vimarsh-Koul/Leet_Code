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
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL)
            return NULL;
        
        ListNode *slow, *fast;
        slow = fast = head;
        if(slow->next==NULL)
            return NULL;
        slow = slow->next;
        fast = fast->next->next;
        
        while(fast!=slow){
            if(!fast || fast->next==NULL)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};