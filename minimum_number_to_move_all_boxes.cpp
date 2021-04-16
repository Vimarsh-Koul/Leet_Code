class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        
        if(boxes.size()==0)
            return ans;
        
        vector<int> ones;
        
        for(int i=0;i<boxes.size();i++)
            if(boxes[i]=='1')
                ones.push_back(i);
        
        for(int i=0;i<boxes.size();i++){
            int temp =0;
            for(auto it : ones)
                temp += abs(it-i);
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};