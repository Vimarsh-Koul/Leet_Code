#include<bits/stdc++.h>
using namespace std;
class tree
{
public:
	int data;
	tree *left;
	tree *right;
};


 void append(tree **head, int data){
 	tree *temp = new tree();
 	temp->data = data;
 	temp->left = temp->right = NULL;

 	if(*head==NULL){
 		*head = temp;
 		return;
 	}

 	tree *prev, *next;
 	prev = NULL;
 	next = *head;

 	while(true){
 		prev = next;
 		if(data<next->data){
 			next = next->left;
 		}

 		else{
 			next=next->right;
 		}

 		if(next==NULL){
 			if(data>prev->data)
 				prev->right = temp;
 			else
 				prev->left = temp;

 			break;
 			
 		}
 	}


 }

 void traverse(tree *head){
 	if(head==NULL)
 		return;
 	traverse(head->left);
 	cout<<head->data<<" ";
 	traverse(head->right);
 }


 void levelordertraversal(tree *head){
 	queue<tree *> q;
 	tree *temp = head;

 	q.push(temp);

 	while(!q.empty()){
 		// cout<<q.data<<" ";
 		tree *mid = q.front();
 		q.pop();
 		cout<<mid->data<<" ";
 		if(mid->left)
 			q.push(mid->left);
 		if(mid->right)
 			q.push(mid->right);

 	}

 }



int main()
{
	tree *head = NULL;

	append(&head, 15);
	append(&head, 10);
	append(&head, 12);
	append(&head, 7);
	append(&head, 90);
	append(&head, 56);
	append(&head, 34);
	cout<<"hello there"<<endl;
	traverse(head);

	cout<<"  "<<endl;
	levelordertraversal(head);


}