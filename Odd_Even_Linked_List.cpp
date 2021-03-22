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
    ListNode* oddEvenList(ListNode* head) {
        int length=2;
        ListNode *temp=head;
        ListNode *last,*firsteven;
        
        if(!head || head->next==NULL || head->next->next==NULL)
            return head;
        firsteven = head->next;
        while(temp->next->next!=NULL){
            temp=temp->next;
            length++;
        }
            
        if(length%2==0)
            last = temp;
        else 
            last = temp->next;

        temp = head;
        while(temp){
            ListNode *nex = temp->next;
            if(nex)
                temp->next = nex->next;
            temp=nex;
        }
        
        last->next = firsteven;
        return head;
        
    }
};