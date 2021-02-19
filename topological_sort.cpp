void sor(vector<int> adj[], stack<int> &s, vector<bool> &visited, int node){
    
    
    
    visited[node] = true;
        for(auto it:adj[node]){
            if(visited[it]==false){
                visited[it]=true;
                // int temp = it;
                sor(adj, s, visited, it);
            }
        }
        s.push(node);
    return ;
}



class Solution{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    vector<int> ans;
	    stack<int> s;
	    vector<bool> visited(V, false);
	    
	    for(int i=0;i<V;i++){
	        if(visited[i]==false){
	            sor(adj, s, visited, i);
	        }
	    }
	    
	    
	    
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
};