class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        
        if(para=="")
            return "";
        
        transform(para.begin(),para.end(), para.begin(), ::tolower);
        
        for(int i= 0 ;i<para.length();i++)
            if(ispunct(para[i]))
                para[i]= ' ';
        
        unordered_map<string, int> m1;
        string temp="";
        for(int i=0;i<para.length();i++){
            if(para[i]!=' ')
                temp=temp+para[i];
            else{
                if(temp!="")
                    m1[temp]++;
                temp="";
            }   
        }
        
        if(temp!="")
            m1[temp]++;

        string fre="";
        int count =-1;
        
        for(int i=0;i<banned.size();i++){
            if(m1[banned[i]])
                m1[banned[i]]=-2;
        }
        
        for(auto it: m1){
            if(it.second>count){
                 fre = it.first;
                count = it.second;
            }
               
        }
        
        return fre;
    }
};