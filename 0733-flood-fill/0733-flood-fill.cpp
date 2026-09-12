class Solution {
public:
    void dfs(vector<vector<int>>&image , int row , int col , int oldC , int newC){
        //boundary check
        if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size()){
            return;
        }

        //different color
        if(image[row][col] != oldC) return;

        //fill current cell
        image[row][col] = newC;

        dfs(image , row - 1 , col , oldC , newC);
        dfs(image , row + 1 , col , oldC , newC);
        dfs(image , row  , col - 1 , oldC , newC);
        dfs(image , row , col + 1 , oldC , newC);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldC = image[sr][sc];
        if(oldC == color) return image;

        dfs(image , sr , sc , oldC , color);
        return image;
    }
};