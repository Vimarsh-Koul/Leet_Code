class Solution {
public:
    
bool IsVowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' ||                    c=='U' ) return 1;
    else return 0;
}
    
    string reverseVowels(string s) {
        int i=0, j=s.size()-1;
    
    while(i<j)
    {
        if(!IsVowel(s[i]) && i<j)  i++;

        else if(!IsVowel(s[j]) && i<j) j--;
    
       else{ swap(s[i],s[j]);i++;j--;}
        
    }
    
    return s;
    }
};