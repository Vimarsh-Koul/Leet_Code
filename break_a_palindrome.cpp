class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        string pal = palindrome;
        
      	if(pal.length()==1 or pal.length()==0)
		return "";

	if(pal[0]!='a'){
		pal[0]='a';
		return pal;
	}


	bool odd = (pal.length()%2!=0);
    char prev = pal[0];
	for(int i=1;i<pal.length();i++){

		if(i==(pal.length()/2) and odd)
			continue;

		if(pal[i]!=prev){
			pal[i] = 'a';
			return pal;
		}
	}

	pal[pal.length()-1] = 'b';
	return pal;  
    }
};