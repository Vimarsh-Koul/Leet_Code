unordered_map<string, bool> mapcheck;

bool solve(string &s1, int i, string &s2, int j, string &s3, int k){
    
    if(i>=s1.length() and j>=s2.length() and k<s3.length())
        return false;
    
    if(k>=s3.length())
        return true;
    
    
    string key = to_string(i) + "*" + to_string(j) + "*" + to_string(k);
    
    if(mapcheck.find(key)!=mapcheck.end())
        return mapcheck[key];
    
    bool check1,check2;
    check1 = check2 = false;
    
    if(i<s1.length() and s1[i] == s3[k])
        check1 = solve(s1, i+1, s2, j, s3, k+1);
    
    if(j<s2.length() and s2[j] == s3[k])
        check2 = solve(s1, i, s2, j+1, s3, k+1);
    
    return mapcheck[key] = check1 or check2;
    
}



class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        mapcheck.clear();
        
        if(s1.length()+ s2.length()!= s3.length())
            return false;
        
        
        return solve(s1, 0, s2, 0, s3, 0);
    }
};