/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node *> q;
        q.push(root);
        unordered_map<int,vector<Node*>> map;
        int level =0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                Node * t= q.front();
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                map[level].push_back(t);
            }
            map[level].push_back(NULL);
            level++;
        }
        for(auto it: map){
            vector<Node *> temp = it.second;
            for(int i=0;i<temp.size()-1;i++){
                temp[i]->next = temp[i+1];
            }
        }
        return root;
    }
};

// ##########################################################

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        unordered_map<int,vector<Node*>> map;
        int level =0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                Node * t= q.front();
                q.pop();
                if(t){
                    if(t->left)
                        q.push(t->left);
                    if(t->right)
                        q.push(t->right);
                    t->next = q.front();
                }   
            }
            q.push(NULL);
            if(q.size()==1)
                break;
        }
        return root;
    }
};





