Node * removeDuplicates( Node *head) 
{
 // your
    unordered_map<int,int> map;
    
    if(head==NULL)
    return NULL;
    
    Node* temp = head;
    Node* prev = NULL;
    
    while(temp){
        if(map[temp->data]){
            Node* t = temp;
            prev->next= temp->next;
            temp=temp->next;
            t->next=NULL;
        }
        else{
            map[temp->data]++;
            prev = temp;
        temp = temp->next;
        }
    }
    
    return head;
}
