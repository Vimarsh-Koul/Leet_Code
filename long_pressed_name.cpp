class Solution {
public:
    bool isLongPressedName(string name, string typed) {
       int i,j;
        i=0;j=0;
        
        if(name.length() > typed.length())
            return false;
        
        
        if(name[0]!=typed[0])
            return false;
        
        while(i<name.size() and j<typed.size()){
            
            if(name[i] == typed[j]){
                i++;
                j++;
            }
             
            else if(name[i]!=typed[j] and name[i-1]== typed[j]){
                
                while(typed[j] == name[i-1])
                    j++;
            }
            
            else if(name[i]!=typed[j] and name[i-1]!=typed[j])
                return false;
                
        }
        
        if(i<name.size())
            return false;
        
        if(j< typed.size()){
            
            while(j<typed.size()){
                if(typed[j]!= name[name.size()-1])
                    return false;
                
                j++;
            }
        }
        
        return true;
        
        
    }
};