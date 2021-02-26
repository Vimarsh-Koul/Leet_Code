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
    
    
    void append(ListNode **start, ListNode** last, int data){
        
        ListNode* temp = new ListNode();
        temp->val = data;
        temp->next=NULL;
        
        if((*start)==NULL){
            *start = *last = temp;
            return;
        }
        
        (*last)->next = temp;
        (*last)= temp;
        return;
        
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        ListNode* start=NULL;
        ListNode* last =NULL;
        
        priority_queue<int,vector<int>, greater<int>> p;
        
        for(auto it: lists){
            ListNode * temp = it;
            while(temp){
                p.push(temp->val);
                temp=temp->next;
            }
        }
        
        while(!p.empty()){
            append(&start, &last, p.top());
            p.pop();
        }
        return start;
    }
};