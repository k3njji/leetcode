class Solution {
public:
    int ans = 0;

    int uniquePathsIII(vector<vector<int>>& grid) {
        int zeroCount = 0;
        int x = 0, y = 0;

        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0) zeroCount++;
                else if(grid[i][j] == 1){
                    x = i; y = j;
                }
            }
        }

        backtrack(grid, x, y, zeroCount, 0);
        return ans;
    }

    void backtrack(vector<vector<int>>& grid, int x, int y, int zeroCount, int count){

        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] < 0){
            return;
        }

        if(grid[x][y] == 2){
            if(count == zeroCount){
                ans++;
            }
            return;
        }

        if(grid[x][y] == 0) count++;

        int temp = grid[x][y];
        grid[x][y] = -2;

        backtrack(grid, x+1, y, zeroCount, count);
        backtrack(grid, x-1, y, zeroCount, count);
        backtrack(grid, x, y+1, zeroCount, count);
        backtrack(grid, x, y-1, zeroCount, count);

        grid[x][y] = temp;
    }
};