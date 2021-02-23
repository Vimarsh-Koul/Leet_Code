class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor)
            return image;
        own(image, sr,sc,newColor, image[sr][sc]);
        return image;
    }
    
     void own(vector<vector<int>> &image, int sr,int sc, int newcolor, int val){
        if(image[sr][sc]!=val)
            return;
        
        image[sr][sc]= newcolor;
        if(sr!=0)
            own(image, sr-1,sc,newcolor,val);
        if(sr!=image.size()-1)
            own(image, sr+1, sc,newcolor, val);
        if(sc!=0)
            own(image,sr,sc-1,newcolor,val);
        if(sc!=image[0].size()-1)
            own(image,sr,sc+1,newcolor,val);
    }
};