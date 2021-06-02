bool check(string &a, int i, int j){
    while(i<j and a[i]==a[j]){
        i++;
        j--;
    }
    
    return i>=j;
}

bool palindrome(string &a, string &b){
    int i,j;
    i=0;
    j = b.length()-1;
    
    while(i<a.length() and j>=0 and a[i]==b[j]){
        i++;
        j--;
    }
    
    return check(a,i,j) or check(b,i,j);
}

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return palindrome(a,b) or palindrome(b,a);
    }
};