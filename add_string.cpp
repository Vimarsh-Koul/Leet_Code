class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1=="0")
            return num2;
        if(num2=="0")
            return num1;
        if(num1=="0" && num2=="0")
            return "0";
        
        int i= num1.length()-1;
        int j = num2.length()-1;
        string ans;
        int carry=0;
        
        while(i>=0 && j>=0){
            int d0 = num1[i]-'0';
            int d1 = num2[j]-'0';
            
            int finald = d0+d1+carry;
            // cout<<finald<<endl;
            if(i==0 && j==0){
                while(finald){
                    ans.push_back(finald%10+'0');
                    finald/=10;
                }
                i--;
                j--;
                break;
            }
            
            ans.push_back(finald%10+'0');
            // cout<<ans<<endl;
            carry=finald/10;
            i--;
            j--;
        }
        
        while(i>=0 && j<0){
            int finald;
                finald = (num1[i]-'0') + carry;
                
                if(i==0){
                    while(finald)
                    {
                    ans.push_back(finald%10+'0');
                    finald/=10;
                }
                    i--;
                    break;
                }
                
                ans.push_back(finald%10+'0');
                carry=finald/10;
                i--;
            
        }
        cout<<ans<<endl;
         
         while(i<0 && j>=0){
           int finald;
                finald = (num2[j]-'0') + carry;

                if(j==0){
                    while(finald){
                        
                        ans.push_back(finald%10+'0');
                        finald/=10;
                    }
                    j--;
                    break;
                }
             
                ans.push_back(finald%10 + '0');
                carry=finald/10;
                j--;

        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};