class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<char,vector<int>> map;
        int mask;
        for(auto word: words){
            mask =0;
            for(int i=0;i<word.length();i++){
                int bit = word[i]-'a';
                mask= mask |  (1<<bit);
            }   
            set<char> temp;
            for(auto it : word)
                temp.insert(it);
            
            for(auto it: temp)
                map[it].push_back(mask);
            
        }
        
        vector<int> ans;
        int count;
        for(auto word: puzzles){
             mask =0;
             for(int i=0;i<word.length();i++){
                 int bit = word[i]-'a';
                 mask= mask | (1<<bit);
             }
            
            vector<int> temp = map[word[0]];
           count =0;
            for(auto it : temp){
                if((mask & it)== it)
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};