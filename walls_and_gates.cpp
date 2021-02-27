class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void dfs(int i, int j, vector<vector<int>> &rooms, int count){
        if(i<0 || i>=rooms.size() || j<0 || j>=rooms[0].size() || rooms[i][j]<count)
        return;

        rooms[i][j]= count;
        dfs(i+1, j, rooms,count+1);
        dfs(i-1,j,rooms,count+1);
        dfs(i,j-1,rooms, count+1);
        dfs(i, j+1, rooms, count+1);
        return;
    }


    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                if(rooms[i][j]==0)
                    dfs(i,j,rooms, 0);
            }
        }
    }
};