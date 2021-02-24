class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        // vector<vector<int>> a;
        if(points.size()==0 || K==0)
            return ans;
        
        // unordered_map<int, vector<int>> map;
        vector<pair<int, vector<int>>> map;
        for(int i=0;i<points.size();i++){
            int dist = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            map.push_back(make_pair(dist, points[i]));
        }
        int j=0;
        sort(map.begin(), map.end());
        
        for(int i=0;i<map.size();i++)
        {
            if(j>=K)
                break;
            ans.push_back(map[i].second);
            j++;
        }
        
        return ans;
    }
};


// ####################################################


class Solution {
public:
    
    bool cmp(vector<int> &a, vector<int> &b){
        return(a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1]);
    }
    
    int sort(vector<vector<int>> &points, int l, int r){
        vector<int> pivot = points[r];
        int p = l-1;
        for(int i=l;i<r;i++){
            if(cmp(points[i], pivot)){
                p++;
                 swap(points[i], points[p]);
            }
        }
        swap(points[p+1],points[r]);
       return p+1; 
    }
    
    void part(vector<vector<int>> &points, int l, int r, int k){
        if(l>=r)
            return;
        int mid = sort(points, l,r);
        if(mid>k)
            part(points, l, mid-1,k);
        else 
            part(points,mid+1,r,k);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        part(points,0,points.size()-1,K);
       vector<vector<int>> ans(points.begin(),points.begin()+K);
        return ans;
    }
};