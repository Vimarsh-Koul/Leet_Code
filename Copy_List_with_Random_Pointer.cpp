/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node *temphead =NULL;
        Node *temp;
        Node* it = head;
        
        while(it){
            Node *temp = new Node(it->val);
            if(!temphead)
                temphead = temp;
            temp->next = it->next;
            it->next = temp;
            it=it->next->next;
        }
        
        it = head;
 
        while(it){
            Node *temp = it->next;
            if(it->random==NULL)
                temp->random = NULL;
            else
                temp->random = it->random->next;
            it=it->next->next;
        }

        temp = temphead;
        Node *head0 = head;
        
        while(temp  && head0){
            head0->next = temp->next;
            if(temp->next)
                temp->next=temp->next->next;
            else
                temp->next = NULL;
            temp=temp->next;
            head0=head0->next;
        }

        return temphead;
    }
};