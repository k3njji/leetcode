class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>> save(
            grid.size(),
            vector<int>(grid[0].size(), 0)
        );

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(save[i][j] == 0){
                    if(traverse(grid, save, i, j, -1, -1, grid[i][j])){
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    bool traverse(vector<vector<char>>& grid,
                  vector<vector<int>>& save,
                  int i, int j,
                  int prevI, int prevJ,
                  char c){

        if(save[i][j] == 1){
            return true;
        }

        save[i][j] = 1;

        if(i + 1 < grid.size() && grid[i + 1][j] == c){
            if(i + 1 != prevI || j != prevJ){
                if(traverse(grid, save, i + 1, j, i, j, c)){
                    return true;
                }
            }
        }

        if(i - 1 >= 0 && grid[i - 1][j] == c){
            if(i - 1 != prevI || j != prevJ){
                if(traverse(grid, save, i - 1, j, i, j, c)){
                    return true;
                }
            }
        }

        if(j + 1 < grid[0].size() && grid[i][j + 1] == c){
            if(i != prevI || j + 1 != prevJ){
                if(traverse(grid, save, i, j + 1, i, j, c)){
                    return true;
                }
            }
        }

        if(j - 1 >= 0 && grid[i][j - 1] == c){
            if(i != prevI || j - 1 != prevJ){
                if(traverse(grid, save, i, j - 1, i, j, c)){
                    return true;
                }
            }
        }

        save[i][j] = 2;
        return false;
    }
};