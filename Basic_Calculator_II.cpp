class Solution {
public:
    int calculate(string s) {
        int lastnumber, result;
        lastnumber = result =0;
        string currentnumber="";
        char op = '+';
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i]))
                currentnumber+=s[i];
            if(!isdigit(s[i]) && s[i]!=' ' || i==s.length()-1){
                if(op=='+' || op=='-'){
                    result+=lastnumber;
                    // cout<<"Lastnumber "<<lastnumber<<" ";
                    lastnumber = (op=='+')? stoi(currentnumber): -stoi(currentnumber);
                    // cout<<"currentnumber "<<currentnumber<<" result "<<result<< endl;
                }
                
                else if(op=='*')
                    lastnumber*= stoi(currentnumber);
                
                
                else if(op=='/')
                    lastnumber/= stoi(currentnumber);
                currentnumber = "";
                op = s[i];
            }
        }
        result+=lastnumber;
        return result;
    }
};