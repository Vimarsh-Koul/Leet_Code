

void has(map<int,vector<Node *>> &m, int level, Node* p){
    if(p==NULL)
    return;
    
    if(p->left!=NULL){
        m[level].push_back(p->left);
        has(m, level+1, p->left);
    }
    
    if(p->right!=NULL){
        m[level].push_back(p->right);
        has(m,level+1, p->right);
    }
        
    
    
}
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes



void connect(Node *p)
{
   // Your Code Here
   if(p==NULL)
   return;
   
   map<int,vector<Node *>> m;
    has(m, 0, p);
   for(auto it: m){
       vector<Node*> v = it.second;
       for(int i=0;i<v.size()-1;i++){
           (v[i])->nextRight= v[i+1];
       }
       (v[v.size()-1])->nextRight = NULL;
   }
   
 
}


