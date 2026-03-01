class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    maxi = max(maxi, traverse(grid, i, j, 1));
                }
            }
        }

        return maxi;
    }

private:
    int traverse(vector<vector<int>>& grid, int i, int j, int count){
        int boundVert = grid.size()-1;
        int boundHorz = grid[i].size()-1;
        grid[i][j] = 0;
        int left = j-1;
        int right = j+1;
        int up = i-1;
        int down = i+1;

        if(left <= boundHorz && left >= 0){
            if(grid[i][left] == 1){
                count += traverse(grid, i, left, 1);
            }
        }
        if(right <= boundHorz && right >= 0){
            if(grid[i][right] == 1){
                count += traverse(grid, i, right, 1);
            }
        }
        if(up >= 0 && up <= boundVert){
            if(grid[up][j] == 1){
                count += traverse(grid, up, j, 1);
            }
        }
        if(down >= 0 && down <= boundVert){
            if(grid[down][j] == 1){
                count += traverse(grid, down, j, 1);
            }
        }

        return count;
    }
};