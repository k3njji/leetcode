class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> hor;
        vector<int> vert;

        int total = 0;

        for(int i = 0; i < grid.size(); i++){
            int max = 0;
            for(int j = 0; j < grid.size(); j++){
                if(max < grid[i][j]){
                    max = grid[i][j];
                }
            }
            hor.push_back(max);
        }

        for(int i = 0; i < grid.size(); i++){
            int max = 0;
            for(int j = 0; j < grid.size(); j++){
                if(max < grid[j][i]){
                    max = grid[j][i];
                }
            }
            vert.push_back(max);
        }

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                total = total + (min(hor[i], vert[j])-grid[i][j]);
            }
        }

        return total;
    }
};