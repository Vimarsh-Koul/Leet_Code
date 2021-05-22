void reverse(vector<vector<int>> &image, int index){
    
    for(int i=0;i<(image[index].size())/2;i++)
        swap(image[index][i], image[index][image[index].size() - i -1]);
    
}

void invert(vector<vector<int>> &image, int index){
    
    for(int i=0;i< image[index].size(); i++){
        if(image[index][i] == 0)
            image[index][i] = 1;
        
        else
            image[index][i] = 0;
    }
    
}

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        for(int i=0;i<image.size(); i++){
            reverse(image, i);
            invert(image, i);        
        }
        
        return image;
        
    }
};