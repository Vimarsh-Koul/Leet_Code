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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev, *temp, *jump;
        
        if(head==NULL)
            return NULL;
        temp = head;
         jump = head;
        prev = NULL;
        // n=n+1;
        while(n--){
            jump = jump->next;
        }
        
        if(jump==NULL){
            
            prev= temp;
            temp = temp->next;
            prev->next = NULL;
            head = temp;
            return head;
            
        }
        
        
        while(jump){
            jump=jump->next;
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        temp->next = NULL;
        return head;
        
    }
};