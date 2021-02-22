class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits=="")
            return ans;
        vector<string> map = {"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        check(digits, "",0,map,ans);
        return ans;
    }
    
    void check(string digits, string temp, int index, vector<string> map, vector<string> &ans){
        if(index==digits.length())
        {
            ans.push_back(temp);
            return;
        }
        
        string letters = map[digits[index]-'0'];
        for(int i=0;i<letters.length();i++)
        {
            check(digits, temp+letters[i], index+1, map, ans);
        }
    }
};