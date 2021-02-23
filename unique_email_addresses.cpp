class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int> map;
        if(emails.size()==0)
            return 0;
        
        for(int i =0;i<emails.size();i++){
            string temp = emails[i];
            string temp0="";
            bool enc = false;
            int j;
            for( j=0;temp[j]!='@';j++){
                if(temp[j]=='+')
                    break;
                else if(temp[j]=='.'){
                    continue;
                }
                
                else{
                    temp0+=temp[j];
                }
            }
            while(temp[j]!='@')
                j++;
           while(j<temp.length()){
               temp0+=temp[j];
               j++;
           } 
        // cout<<temp0<<" ";
        map[temp0]++;
        }
        return map.size();
    }
};