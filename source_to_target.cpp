void allpairs(vector<vector<int>> graph, vector<int> path, vector<vector<int>> &paths, int pos, int des)
{
    if(pos==des){
        paths.push_back(path);
        return;
    }
    
    
    for(auto it: graph[pos]){
        path.push_back(it);
        allpairs(graph, path, paths, it, des);
        path.pop_back();
    }
        
    
}

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path(1,0);
        vector<vector<int>> paths;
        allpairs( graph,  path,  paths,0, graph.size()-1);
        return paths;
    }
};