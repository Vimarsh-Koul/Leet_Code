class Solution {
public:
    int compress(vector<char>& chars) {
        int i, j;
        i=j=0;
        string temp="";
        while(i<chars.size() && j<chars.size()){
            if(chars[i]==chars[j])
                j++;
            
            else{
                int count = j-i;
                temp+=chars[i];
                if(count>1)
                    temp+=to_string(count);
                i=j;
            }
        }
        
        if(j-i>0){
            temp+=chars[i];
            if(j-i>1)
                temp+=to_string(j-i);
        }
        chars.clear();
        for(auto it: temp)
            chars.push_back(it);
        return temp.length();
    }
};