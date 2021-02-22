class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> j;
        if(jewels=="")
            return 0;
        for(int i=0;i<jewels.length();i++)
            j[jewels[i]]++;
        
        int check =0;
        for(int i=0;i<stones.length();i++)
            if(j[stones[i]])
                check++;
        return check;
    }
};